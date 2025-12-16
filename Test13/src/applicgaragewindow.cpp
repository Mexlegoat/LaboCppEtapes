#include "applicgaragewindow.h"
#include "ui_applicgaragewindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <sstream>
#include <iostream>
#include "unistd.h"
#include "Garage.h"

#define IMAGES_DIR "../../images/"
#define CSV "../../CSVs/"
using namespace carconfig;

auto &g = Garage::getInstance();
Car c = g.getCurrentProject();
ApplicGarageWindow::ApplicGarageWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::ApplicGarageWindow)
{
    ui->setupUi(this);
    ::close(2);

    // Configuration de la table des options (projet en cours)
    ui->tableWidgetOptions->setColumnCount(3);
    ui->tableWidgetOptions->setRowCount(5);
    for (int i=0 ; i<5 ; i++) ui->tableWidgetOptions->setRowHeight(i,10);
    QStringList labelsTableOptions;
    labelsTableOptions << "Code" << "Prix" << "Intitulé";
    ui->tableWidgetOptions->setHorizontalHeaderLabels(labelsTableOptions);
    ui->tableWidgetOptions->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetOptions->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetOptions->horizontalHeader()->setVisible(true);
    ui->tableWidgetOptions->horizontalHeader()->setDefaultSectionSize(60);
    ui->tableWidgetOptions->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetOptions->verticalHeader()->setVisible(false);
    ui->tableWidgetOptions->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des employes (Personnel Garage)
    ui->tableWidgetEmployees->setColumnCount(4);
    ui->tableWidgetEmployees->setRowCount(0);
    QStringList labelsTableEmployes;
    labelsTableEmployes << "Numéro" << "Nom" << "Prénom" << "Fonction";
    ui->tableWidgetEmployees->setHorizontalHeaderLabels(labelsTableEmployes);
    ui->tableWidgetEmployees->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetEmployees->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetEmployees->horizontalHeader()->setVisible(true);
    ui->tableWidgetEmployees->horizontalHeader()->setDefaultSectionSize(80);
    ui->tableWidgetEmployees->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetEmployees->verticalHeader()->setVisible(false);
    ui->tableWidgetEmployees->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des clients
    ui->tableWidgetClients->setColumnCount(4);
    ui->tableWidgetClients->setRowCount(0);
    QStringList labelsTableClients;
    labelsTableClients << "Numéro" << "Nom" << "Prénom" << "GSM";
    ui->tableWidgetClients->setHorizontalHeaderLabels(labelsTableClients);
    ui->tableWidgetClients->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetClients->horizontalHeader()->setVisible(true);
    ui->tableWidgetClients->horizontalHeader()->setDefaultSectionSize(80);
    ui->tableWidgetClients->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetClients->verticalHeader()->setVisible(false);
    ui->tableWidgetClients->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des contrats
    ui->tableWidgetContracts->setColumnCount(4);
    ui->tableWidgetContracts->setRowCount(0);
    QStringList labelsTableContrats;
    labelsTableContrats << "Numéro" << "Vendeur" << "Client" << "Voiture";
    ui->tableWidgetContracts->setHorizontalHeaderLabels(labelsTableContrats);
    ui->tableWidgetContracts->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetContracts->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetContracts->horizontalHeader()->setVisible(true);
    ui->tableWidgetContracts->horizontalHeader()->setDefaultSectionSize(80);
    ui->tableWidgetContracts->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetContracts->verticalHeader()->setVisible(false);
    ui->tableWidgetContracts->horizontalHeader()->setStyleSheet("background-color: lightyellow");


    // Importation des modeles (étape 10)
    auto &garage = Garage::getInstance();

    garage.importModelsFromCsv(CSV);
    garage.importOptionsFromCsv(CSV);
    int i = 0;

    do
    {
        Model m = garage.getModel(i);
        i++;
        if (m.getImage().empty())
        {
            break;
        }
        addAvailableModel(m.getName(), m.getBasePrice());
    } while(true);

    // Importation des options (étape 10)
    clearTableOption();
    i = 0;

    do
    {
        Option o = garage.getOption(i);
        i++;
        if (o.getLabel().empty())
        {
            break;
        }
        addAvailableOption(o.getLabel(), o.getPrice());
    } while(true);

    // Lecture de config.dat, des employees, clients et contrats (étape 12)
    garage.load();
    auto &employees = garage.getEmployees();
    for(auto it = employees.cbegin(); it != employees.cend(); ++it)
    {
        addTupleTableEmployees(it->tuple());

    }
    auto& clients = garage.getClients();
    for(auto it = clients.cbegin(); it != clients.cend(); ++it)
    {
        addTupleTableClients(it->tuple());
    }
    auto& contracts = garage.getContracts();
    for(auto it = contracts.cbegin(); it != contracts.cend(); ++it)
    {
        addTupleTableContracts(it->tuple());

    }
    setRole();

    // ***** TESTS de l'interfac graphique (à supprimer) *****
}

ApplicGarageWindow::~ApplicGarageWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Méthodes de la fenêtre /////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setTitle(string title)
{
    this->setWindowTitle(title.c_str());
}

void ApplicGarageWindow::setRole(int val)
{
    // val = 0 --> personne n'est loggé
    // val = 1 --> un administratif est loggé
    // val = 2 --> un vendeur loggé
    // val = 3 --> on a accès à tout

    if (val == 0)
    {
        ui->actionLogin->setEnabled(true);
        ui->actionLogout->setEnabled(false);
        ui->actionResetPassword->setEnabled(false);

        ui->menuEmployees->setEnabled(false);

        ui->menuClients->setEnabled(false);

        ui->menuCar->setEnabled(false);
        ui->comboBoxAvailableModels->setEnabled(false);
        ui->comboBoxAvailableOptions->setEnabled(false);
        ui->pushButtonOpenProject->setEnabled(false);
        ui->pushButtonNewProject->setEnabled(false);
        ui->pushButtonReduction->setEnabled(false);
        ui->pushButtonSaveProject->setEnabled(false);
        ui->pushButtonAddOption->setEnabled(false);
        ui->pushButtonRemoveOption->setEnabled(false);
        ui->pushButtonSelectModel->setEnabled(false);

        ui->pushButtonShowCar->setEnabled(false);
        ui->pushButtonNewContract->setEnabled(false);
        ui->pushButtonDeleteContract->setEnabled(false);
    }

    if (val == 1)
    {
        ui->actionLogin->setEnabled(false);
        ui->actionLogout->setEnabled(true);
        ui->actionResetPassword->setEnabled(true);

        ui->menuEmployees->setEnabled(true);

        ui->menuClients->setEnabled(false);

        ui->menuCar->setEnabled(false);
        ui->comboBoxAvailableModels->setEnabled(false);
        ui->comboBoxAvailableOptions->setEnabled(false);
        ui->pushButtonOpenProject->setEnabled(false);
        ui->pushButtonNewProject->setEnabled(false);
        ui->pushButtonReduction->setEnabled(false);
        ui->pushButtonSaveProject->setEnabled(false);
        ui->pushButtonAddOption->setEnabled(false);
        ui->pushButtonRemoveOption->setEnabled(false);
        ui->pushButtonSelectModel->setEnabled(false);

        ui->pushButtonShowCar->setEnabled(true);
        ui->pushButtonNewContract->setEnabled(false);
        ui->pushButtonDeleteContract->setEnabled(true);
    }

    if (val == 2)
    {
        ui->actionLogin->setEnabled(false);
        ui->actionLogout->setEnabled(true);
        ui->actionResetPassword->setEnabled(true);

        ui->menuEmployees->setEnabled(false);

        ui->menuClients->setEnabled(true);

        ui->menuCar->setEnabled(true);
        ui->comboBoxAvailableModels->setEnabled(true);
        ui->comboBoxAvailableOptions->setEnabled(true);
        ui->pushButtonOpenProject->setEnabled(true);
        ui->pushButtonNewProject->setEnabled(true);
        ui->pushButtonReduction->setEnabled(true);
        ui->pushButtonSaveProject->setEnabled(true);
        ui->pushButtonAddOption->setEnabled(true);
        ui->pushButtonRemoveOption->setEnabled(true);
        ui->pushButtonSelectModel->setEnabled(true);

        ui->pushButtonShowCar->setEnabled(true);
        ui->pushButtonNewContract->setEnabled(true);
        ui->pushButtonDeleteContract->setEnabled(true);
    }

    if (val == 3)
    {
        ui->actionLogin->setEnabled(true);
        ui->actionLogout->setEnabled(true);
        ui->actionResetPassword->setEnabled(true);

        ui->menuEmployees->setEnabled(true);

        ui->menuClients->setEnabled(true);

        ui->menuCar->setEnabled(true);
        ui->comboBoxAvailableModels->setEnabled(true);
        ui->comboBoxAvailableOptions->setEnabled(true);
        ui->pushButtonOpenProject->setEnabled(true);
        ui->pushButtonNewProject->setEnabled(true);
        ui->pushButtonReduction->setEnabled(true);
        ui->pushButtonSaveProject->setEnabled(true);
        ui->pushButtonAddOption->setEnabled(true);
        ui->pushButtonRemoveOption->setEnabled(true);
        ui->pushButtonSelectModel->setEnabled(true);

        ui->pushButtonShowCar->setEnabled(true);
        ui->pushButtonNewContract->setEnabled(true);
        ui->pushButtonDeleteContract->setEnabled(true);
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Table des options du projet en cours (ne pas modifier) /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setTableOption(int index,string code,string label,float price)
{
    // Modifie l'option de la ligne correspondant à l'indice fourni dans la table des options de l'interface graphique
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(code.c_str());
    ui->tableWidgetOptions->setItem(index,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    char tmp[20];
    sprintf(tmp,"%.2f",price);
    if (price < 0.0) item->setText("");
    else item->setText(tmp);
    ui->tableWidgetOptions->setItem(index,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(label.c_str());
    ui->tableWidgetOptions->setItem(index,2,item);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::clearTableOption()
{
    for (int i=0 ; i<5 ; i++) setTableOption(i);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndexOptionSelectionTable() const
{
    // retourne l'indice de l'option selectionnee dans la table des options
    QModelIndexList list = ui->tableWidgetOptions->selectionModel()->selectedRows();
    if (list.size() == 0) return -1;
    QModelIndex index = list.at(0);
    int ind = index.row();
    return ind;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Combobox des modèles disponibles (ne pas modifier) /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::addAvailableModel(string name,float basePrice)
{
    // ajoute un modèle dans le combobox correspondant (juste le nom et le prix)
    stringstream ss;
    char temp[20];
    sprintf(temp,"%.2f",basePrice);
    ss << name.c_str() << " (" << temp << ")";
    ui->comboBoxAvailableModels->addItem(ss.str().c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::clearComboBoxAvailableModels()
{
    ui->comboBoxAvailableModels->clear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndexModelSelectionCombobox() const
{
    // retourne l'indice du modèle selectionné dans le combobox des modèles
    return ui->comboBoxAvailableModels->currentIndex();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Combox des options disponibles (ne pas modifier) ///////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::addAvailableOption(string label,float price)
{
    // ajoute une option dans le combobox correspondant
    stringstream ss;
    char temp[20];
    sprintf(temp,"%.2f",price);
    ss << label << " (" << temp << ")";
    ui->comboBoxAvailableOptions->addItem(ss.str().c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::clearComboBoxAvailableOptions()
{
    ui->comboBoxAvailableOptions->clear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndexOptionSelectionCombobox() const
{
    // retourne l'indice de l'option selectionnée dans le combobox des options
    return ui->comboBoxAvailableOptions->currentIndex();
}

///////////////////////////////////////////////////////////////////////²////////////////////////////////////////
///// Gestion I/O Projet en cours (ne pas modifier) //////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setCurrentProjectName(string name)
{
    // Remplit le champ nom de l'interface graphique avec le nom reçu
    ui->lineEditProjectName->setText(name.c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicGarageWindow::getCurrentProjectName() const
{
    return ui->lineEditProjectName->text().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setModel(string name,int power,int engine,float basePrice,string modelImage)
{
    // Remplit les champs correspondants dans l'interface graphique
    // pour le moteur (int) : 0=Essence, 1=Diesel, 2=Electrique, 3=Hybride
    ui->lineEditModelName->setText(name.c_str());
    ui->lineEditPower->setText(to_string(power).c_str());
    char tmp[20];
    sprintf(tmp,"%.2f",basePrice);
    ui->lineEditBasePrice->setText(tmp);

    ui->radioButtonPetrol->setChecked(false);
    ui->radioButtonDiesel->setChecked(false);
    ui->radioButtonElectric->setChecked(false);
    ui->radioButtonHybrid->setChecked(false);

    if (engine == 0) ui->radioButtonPetrol->setChecked(true);
    if (engine == 1) ui->radioButtonDiesel->setChecked(true);
    if (engine == 2) ui->radioButtonElectric->setChecked(true);
    if (engine == 3) ui->radioButtonHybrid->setChecked(true);

    // Met à jour l'image du modèle
    string cheminComplet = IMAGES_DIR + modelImage;
    QLabel* label = new QLabel();
    label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    label->setScaledContents(true);
    QPixmap *pixmap_img = new QPixmap(cheminComplet.c_str());
    label->setPixmap(*pixmap_img);
    label->resize(label->pixmap()->size());
    ui->scrollArea->setWidget(label);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::setPrice(float price)
{
  char tmp[20];
  sprintf(tmp,"%.2f",price);
  ui->lineEditPrice->setText(tmp);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Employes (ne pas modifier) //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::addTupleTableEmployees(string tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple.c_str(),199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char id[20];
    strcpy(id,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char name[40];
    strcpy(name,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char firstName[40];
    strcpy(firstName,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char fonction[40];
    strcpy(fonction,tmp);

    // Ajout possible
    int nbLines = ui->tableWidgetEmployees->rowCount();
    nbLines++;
    ui->tableWidgetEmployees->setRowCount(nbLines);
    ui->tableWidgetEmployees->setRowHeight(nbLines-1,10);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(id);
    ui->tableWidgetEmployees->setItem(nbLines-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(name);
    ui->tableWidgetEmployees->setItem(nbLines-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(firstName);
    ui->tableWidgetEmployees->setItem(nbLines-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(fonction);
    ui->tableWidgetEmployees->setItem(nbLines-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::clearTableEmployees()
{
    ui->tableWidgetEmployees->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndexEmployeeSelectionTable()
{
    QModelIndexList liste = ui->tableWidgetEmployees->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int ind = index.row();
    return ind;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Clients (ne pas modifier) ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::addTupleTableClients(string tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple.c_str(),199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char id[20];
    strcpy(id,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char lastName[40];
    strcpy(lastName,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char firstName[40];
    strcpy(firstName,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char gsm[40];
    strcpy(gsm,tmp);

    // Ajout possible
    int nbLines = ui->tableWidgetClients->rowCount();
    nbLines++;
    ui->tableWidgetClients->setRowCount(nbLines);
    ui->tableWidgetClients->setRowHeight(nbLines-1,10);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(id);
    ui->tableWidgetClients->setItem(nbLines-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(lastName);
    ui->tableWidgetClients->setItem(nbLines-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(firstName);
    ui->tableWidgetClients->setItem(nbLines-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(gsm);
    ui->tableWidgetClients->setItem(nbLines-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::clearTableClients()
{
    ui->tableWidgetClients->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndexClientSelectionTable()
{
    QModelIndexList liste = ui->tableWidgetClients->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int ind = index.row();
    return ind;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des Contrats (ne pas modifier) //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::addTupleTableContracts(string tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple.c_str(),199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char id[20];
    strcpy(id,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char seller[40];
    strcpy(seller,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char client[40];
    strcpy(client,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char car[40];
    strcpy(car,tmp);

    // Ajout possible
    int nbLines = ui->tableWidgetContracts->rowCount();
    nbLines++;
    ui->tableWidgetContracts->setRowCount(nbLines);
    ui->tableWidgetContracts->setRowHeight(nbLines-1,10);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(id);
    ui->tableWidgetContracts->setItem(nbLines-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(seller);
    ui->tableWidgetContracts->setItem(nbLines-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(client);
    ui->tableWidgetContracts->setItem(nbLines-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(car);
    ui->tableWidgetContracts->setItem(nbLines-1,3,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::clearTableContracts()
{
    ui->tableWidgetContracts->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::getIndexContractSelectionTable()
{
    QModelIndexList liste = ui->tableWidgetContracts->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int ind = index.row();
    return ind;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions permettant d'afficher des boites de dialogue /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::dialogMessage(const char* title,const char* message)
{
   QMessageBox::information(this,title,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::dialogError(const char* title,const char* message)
{
   QMessageBox::critical(this,title,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicGarageWindow::dialogPromptText(const char* title,const char* question)
{
    QString chaine = QInputDialog::getText(this,title,question);
    return chaine.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicGarageWindow::dialogPromptInt(const char* title,const char* question)
{
    return QInputDialog::getInt(this,title,question);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
float ApplicGarageWindow::dialogPromptFloat(const char* title,const char* question)
{
    return QInputDialog::getDouble(this,title,question);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les items de menu //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionQuit_triggered()
{
    // TO DO (étape 12)
    cout << ">>> Clic sur item Quitter <<<" << endl;
    auto& garage = Garage::getInstance();
    garage.save();

    QApplication::exit();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::closeEvent(QCloseEvent *event)
{
    // TO DO (étape 12)
    auto& garage = Garage::getInstance();
    garage.save();
    cout << ">>> Clic sur croix de fenetre <<<" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionNewModel_triggered()
{
    // TO DO (étape 9)
    Model m;    

    string modelName = this->dialogPromptText("Nouveau modèle","Nom :");
    int power = this->dialogPromptInt("Nouveau modèle","Puissance :");
    if (power < 0)
    {
        dialogError("Erreur Power","Le nombre que vous avez saisi est négatif!");
        return;
    }
    int engine = this->dialogPromptInt("Nouveau modèle :","Moteur (0=essence,1=diesel,2=électrique,3=hybride) :");
    if (engine < 0 || engine > 3)
    {
        dialogError("Erreur Engine","Le nombre que vous avez saisi est invalide!");
        return;
    }
    float basePrice = this->dialogPromptFloat("Nouveau modèle","Prix de base :");
    if (basePrice < 0)
    {
        dialogError("Erreur basePrice","Le nombre que vous avez saisi est négatif!");
        return;
    }
    string image = this->dialogPromptText("Nouveau modèle","Nom du fichier de l'image :");

    m.setName(modelName.c_str());
    m.setEngine(engine);
    m.setPower(power);
    m.setBasePrice(basePrice);
    m.setImage(image);
    cout << ">>> Clic sur item NewModel <<<" << endl;
    cout << "modelName = " << modelName << endl;
    cout << "power = " << power << endl;
    cout << "engine = " << engine << endl;
    cout << "basePrice = " << basePrice << endl;
    cout << "image = " << image << endl;
    addAvailableModel(modelName, basePrice);
    Garage::getInstance().addModel(m); // ! le constructeur de copie doit contenir le setImage() dans Model.cpp
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionNewOption_triggered()
{
    // TO DO (étape 9)
    Option o;  
    string code = this->dialogPromptText("Nouvelle option","Code :");
    string label = this->dialogPromptText("Nouvelle option","Intitule :");
    float price = this->dialogPromptFloat("Nouvelle option","Prix :");
    try
    {
        o.setCode(code);
        o.setLabel(label);
        o.setPrice(price);
    }
    catch(OptionException& o)
    {
        cout << o.getMessage();
        dialogError("Erreur lors de la saisie", o.getMessage().c_str());
        return;
    }

    cout << ">>> Clic sur item NewOption <<<" << endl;
    cout << "code = " << code << endl;
    cout << "label = " << label << endl;
    cout << "price = " << price << endl;
    addAvailableOption(label, price);
    Garage::getInstance().addOption(o);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionAddEmployee_triggered()
{
    // TO DO (étape 11)

    string lastName = this->dialogPromptText("Nouvel employé","Nom :");
    string firstName = this->dialogPromptText("Nouvel employé","Prénom :");
    string login = this->dialogPromptText("Nouvel employé","Login :");
    int type = this->dialogPromptInt("Nouvel employé","Fonction (0=administratif,1=vendeur) :");
    Employee e;
    string tuple;
    e.setLastName(lastName);
    e.setFirstName(firstName);
    e.setLogin(login);
    e.setRole(type);
    auto &garage = Garage::getInstance();
    auto &employees = garage.getEmployees();
    for (auto it = employees.cbegin(); it != employees.cend(); ++it) 
    {
        if(e.getLogin() == it->getLogin())
        {
            dialogError("Erreur doublon", "Le login que vous venez de saisir est deja utilisé");
            return;
        }
        else if (e.getLastName() == it->getLastName())
        {
            dialogError("Erreur doublon", "Le nom que vous venez de saisir est deja utilisé");
            return;
        }
        else if (e.getFirstName() == it->getFirstName())
        {
            dialogError("Erreur doublon", "Le prénom que vous venez de saisir est deja utilisé");
            return;
        }
    }
    clearTableEmployees();
    garage.addEmployee(lastName, firstName, e.getLogin(), e.getRole());

    for (auto it = employees.cbegin(); it != employees.cend(); ++it) 
    {
        addTupleTableEmployees(it->tuple());
    }
    cout << ">>> Clic sur item AddEmployee <<<" << endl;
    cout << "lastName = " << lastName << endl;
    cout << "firstName = " << firstName << endl;
    cout << "login = " << login << endl;
    cout << "type = " << type << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionDeleteEmployeeById_triggered()
{
    // TO DO (étape 11)
    int id = dialogPromptInt("Supprimer Employee", "Id:");
    auto &garage = Garage::getInstance();
    Employee e = garage.findEmployeeById(id);
    if (e.getLogin().empty())
    {
        dialogError("Supprimer Employee", "Erreur, l'id que vous avez saisi est soit une id client soit n'existe pas");
        return;
    }
    garage.deleteEmployeeById(id);
    clearTableEmployees();
    auto &employees = garage.getEmployees();
    for (auto it = employees.cbegin(); it != employees.cend(); ++it) 
    {
        addTupleTableEmployees(it->tuple());
    }
    cout << ">>> Clic sur item DeleteEmployeeById <<<" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionDeleteEmployeeByIndex_triggered()
{
    // TO DO (étape 11)
    int indice = getIndexEmployeeSelectionTable();
    if (indice == -1)
    {
        dialogError("Supprimer Employee (SELECTION)", "Erreur, vous n'avez rien selectionné");
        return;
    }
    else
    {
        auto& garage = Garage::getInstance();
        auto& employees = garage.getEmployees();
        garage.deleteEmployeeByIndex(indice);
        clearTableEmployees();
        for(auto it = employees.cbegin(); it != employees.cend(); ++it)
        {
            addTupleTableEmployees(it->tuple());

        }
    }
    cout << ">>> Clic sur item DeleteEmployeeByIndex <<<" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionAddClient_triggered()
{
    // TO DO (étape 11)
    string lastName = this->dialogPromptText("Nouveau client","Nom :");
    string firstName = this->dialogPromptText("Nouveau client","Prénom :");
    string gsm = this->dialogPromptText("Nouveau client","gsm:");
    clearTableClients();
    Client c;
    string tuple;
    c.setLastName(lastName);
    c.setFirstName(firstName);
    c.setGsm(gsm);
    auto &garage = Garage::getInstance();
    auto &clients = garage.getClients();
    garage.addClient(lastName, firstName, gsm);
    for(auto it = clients.cbegin(); it != clients.cend(); ++it)
    {
        addTupleTableClients(it->tuple());

    }
    cout << ">>> Clic sur item AddClient <<<" << endl;
    cout << "lastName = " << lastName << endl;
    cout << "firstName = " << firstName << endl;
    cout << "gsm = " << gsm << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionDeleteClientById_triggered()
{
    // TO DO (étape 11)
    int id = dialogPromptInt("Supprimer Client", "Id:");
    auto &garage = Garage::getInstance();
    auto &clients = garage.getClients();
    Client c = garage.findClientById(id);
    if (c.getGsm().empty())
    {
        dialogError("Supprimer Clients", "Erreur, l'id que vous avez saisi est soit une id employee soit il n'existe pas");
        return;
    }
    garage.deleteClientById(id);
    clearTableClients();
    for(auto it = clients.cbegin(); it != clients.cend(); ++it)
    {
        addTupleTableClients(it->tuple());

    }
    cout << ">>> Clic sur item DeleteClientById <<<" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionDeleteClientByIndex_triggered()
{
    // TO DO (étape 11)
    int indice = getIndexClientSelectionTable();
    if (indice == -1)
    {
        dialogError("Supprimer Client (SELECTION)", "Erreur, vous n'avez rien selectionné");
        return;
    }
    else
    {
        auto& garage = Garage::getInstance();
        auto& clients = garage.getClients();
        garage.deleteClientByIndex(indice);
        clearTableClients();
        for(auto it = clients.cbegin(); it != clients.cend(); ++it)
        {
            addTupleTableClients(it->tuple());

        }
    }

    cout << ">>> Clic sur item DeleteClientByIndex <<<" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionLogin_triggered()
{
    // TO DO (étape 11)
    string login = dialogPromptText("Login", "Veuillez saisir un login");
    if (login.empty())
    {
        dialogError("Erreur Login", "Le login que vous avez saisie est vide");
        return;
    }
    auto& garage = Garage::getInstance();
    auto& employees = garage.getEmployees();
    int d;
    bool isTrue = false;
    string pwd;
    for(auto it = employees.cbegin(); it != employees.cend(); ++it) // on essaye de voir si l'utilisateur existe dans la liste
    {
        if(login == it->getLogin()) // si il existe
        {
            isTrue = true;
            cout << "Test:" << it->getId() << endl;
            d = it->getId();
            garage.setId(d); 
            break;
        }
    }
    if (!isTrue) // si il n'existe pas
    {
        dialogError("Erreur Login", "Le login n'existe pas");
        return;
    }
    cout << "Id avant= " << garage.getId();
    Employee e = garage.findEmployeeById(garage.getId());
    try
    {
        pwd = e.getPassword(); // on regarde si l'employé a un mdp
        string pw = dialogPromptText("Mot de passe", "Veuillez saisir un mot de passe");
        if (pw != pwd) // si faux
        {
            dialogError("Mot de passe", "Mot de passe invalide");
            return;
        }
    }
    catch(PasswordException& pw)
    {
        bool ok = false;
        dialogError("Pas de mot de passe", "L'utilisateur n'a pas de mot de passe, vous devez en creer un");
        while(!ok)
        {
            pwd = dialogPromptText("Mot de passe", "Veuillez saisir un mot de passe");
            try
            {
                e.setPassword(pwd);
                garage.modifyEmployee(e, garage.getId());
                cout << "Id après: " << garage.getId();
                ok = true;
            }
            catch(PasswordException& p)
            {
                dialogError("Mot de passe", "Mot de passe incorrect");
            }
        }
    }
    cout << e.getRole() << endl;
    if (e.getRole() == "Vendeur")
    {
        setRole(2);
        clearTableEmployees();
        clearTableClients();
        clearTableContracts();
        for(auto it = employees.cbegin(); it != employees.cend(); ++it)
        {
            addTupleTableEmployees(it->tuple());

        }
        auto& clients = garage.getClients();
        for(auto it = clients.cbegin(); it != clients.cend(); ++it)
        {
            addTupleTableClients(it->tuple());
        }
        auto& contracts = garage.getContracts();
        for(auto it = contracts.cbegin(); it != contracts.cend(); ++it)
        {
            addTupleTableContracts(it->tuple());

        }
    }
    else if (e.getRole() == "Administratif")
    {
        setRole(1);
        clearTableEmployees();
        clearTableClients();
        for(auto it = employees.cbegin(); it != employees.cend(); ++it)
        {
            addTupleTableEmployees(it->tuple());

        }
        auto& clients = garage.getClients();
        for(auto it = clients.cbegin(); it != clients.cend(); ++it)
        {
            addTupleTableClients(it->tuple());
        }
    }

    cout << ">>> Clic sur item Login <<<" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionLogout_triggered()
{
    // TO DO (étape 11)
    setRole(0);
    Garage::getInstance().resetCurrentProject();
    c = Garage::getInstance().getCurrentProject();
    clearTableOption();
    clearTableClients();
    clearTableContracts();
    clearTableEmployees();
    clearComboBoxAvailableModels();
    clearComboBoxAvailableOptions();
    setPrice(0);

    setModel("---", 0, 0, float(0), "---");
    setCurrentProjectName("---");
    auto &garage = Garage::getInstance();
    garage.setId(-1);
    cout << "id garage: " << garage.getId() << endl;
    garage.importModelsFromCsv(CSV);
    garage.importOptionsFromCsv(CSV);
    int i = 0;

    do
    {
        Model m = garage.getModel(i);
        i++;
        if (m.getImage().empty())
        {
            break;
        }
        addAvailableModel(m.getName(), m.getBasePrice());
    } while(true);

    // Importation des options (étape 10)
    clearTableOption();
    i = 0;

    do
    {
        Option o = garage.getOption(i);
        i++;
        if (o.getLabel().empty())
        {
            break;
        }
        addAvailableOption(o.getLabel(), o.getPrice());
    } while(true);
    cout << ">>> Clic sur item Logout <<<" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_actionResetPassword_triggered()
{
    // TO DO (étape 11)
    auto &garage = Garage::getInstance();
    Employee e = garage.findEmployeeById(garage.getId()); // on recherche l'employé
    e.resetPassword();
    garage.modifyEmployee(e, garage.getId()); // cette fonction je l'ai ajouté pour aller à l'employé sans besoin de boucle
    dialogMessage("Reset Password", "Votre mot de passe a été réinstialisé avec succès.\nSi vous vous deconnectez, vous devez remettre un mot de passe");

    cout << ">>> clic sur item ResetPassword <<<" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonSelectModel_clicked()
{
    // TO DO (étape 9)
    cout << ">>> Clic sur bouton SelectModel <<<" << endl;
    int indice = getIndexModelSelectionCombobox();
    float price;
    Model m;
    if (indice == -1)
    {
        dialogError("Erreur Selection", "Vous n'avez rien selectionné!");
        return;
    }
    else
    {
        m = Garage::getInstance().getModel(indice);
        c.setModel(m);
        price = c.getPrice();
        setModel(string(m.getName()), m.getPower(), m.getEngine(), m.getBasePrice(), m.getImage());
        setPrice(price);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonAddOption_clicked()
{
    // TO DO (étape 9)
    cout << ">>> Clic sur bouton AddOption <<<" << endl;
    int indice = getIndexOptionSelectionCombobox();
    float price;
    Option o;

    int index = -1;
    for (int i = 0; i < 5; i++)
    {
        if (c[i] == nullptr)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        dialogError("Erreur Ajout", "Vous ne pouvez pas ajouter plus que 5 options");
        return;
    }
    if (indice == -1)
    {
        dialogError("Erreur Selection", "Vous n'avez rien selectionné!");
        return;
    }
    else
    {
        o = Garage::getInstance().getOption(indice);
        try
        {
            c.addOption(o);
        }
        catch(OptionException& op)
        {
            dialogError("Erreur doublon",op.getMessage().c_str());
            return;
        }
        price = c.getPrice();
        setTableOption(index, o.getCode(), o.getLabel(), o.getPrice());
        setPrice(price);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonRemoveOption_clicked()
{
    // TO DO (étape 9)
    cout << ">>> Clic sur bouton RemoveOption <<<" << endl;
    int indice = getIndexOptionSelectionTable();
    float price;
    if (indice == -1)
    {
        dialogError("Erreur Selection", "Vous n'avez rien selectionné!");
        return;
    }
    else
    {
        if (c[indice] != nullptr)
        {
            try
            {
                string code = c[indice]->getCode();
                c.removeOption(code);
            }
            catch(OptionException& op)
            {
                dialogError("Erreur doublon",op.getMessage().c_str());
                return;
            }
            price = c.getPrice();
            setTableOption(indice);
            setPrice(price);
        }
        else
        {
            dialogError("Erreur Selection", "Vous n'avez rien selectionné!");
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonReduction_clicked()
{
    // TO DO (étape 9)
    cout << ">>> Clic sur bouton Reduction <<<" << endl;
    int indice = getIndexOptionSelectionTable();
    float price;
    Option op;
    if (indice == -1)
    {
        dialogError("Erreur Selection", "Vous avez choisis une option vide");
        return;
    }
    else
    {
        if (c[indice] != nullptr)
        {
            op.setLabel(c[indice]->getLabel());
            try
            {
                op.setPrice(c[indice]->getPrice()); // On récupère le prix
                op--; // on décrémente
                c[indice]->setPrice(op.getPrice()); // on remet le prix dans car comme ça la prochaine fois on aura ce prix la et pas l'autre
            }
            catch(OptionException& o)
            {
                dialogError("Erreur Prix", o.getMessage().c_str());
            }
            price = c.getPrice();
            setTableOption(indice, c[indice]->getCode(), c[indice]->getLabel(), c[indice]->getPrice());
            setPrice(price);
        }
        else
        {
            dialogError("Erreur Selection", "Vous n'avez rien selectionné!");
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonSaveProject_clicked()
{
    // TO DO (étape 9)
    cout << ">>> Clic sur bouton SaveProject <<<" << endl;
    string projectName = getCurrentProjectName();
    if (projectName == "")
    {
        dialogError("Erreur Saisie", "Le nom du projet est vide");
        return;
    }
    else
    {
        c.setName(projectName);
        c.save();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonOpenProject_clicked()
{
    // TO DO (étape 9)
    cout << ">>> Clic sur bouton OpenProject <<<" << endl;
    string projectName = getCurrentProjectName();
    c.load(projectName);

    // Model
    Model m = c.getModel();
    setModel(string(m.getName()), m.getPower(), m.getEngine(), m.getBasePrice(), m.getImage());
    // Option
    for (int i = 0; i < 5; i++)
    {
        Option* o = c[i];
        if (o != nullptr)
        {
            setTableOption(i, o->getCode(), o->getLabel(), o->getPrice());
        }
        else
        {
            setTableOption(i);
        }
    }
    setPrice(c.getPrice());
    setCurrentProjectName(projectName);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonNewProject_clicked()
{
    // TO DO (étape 9)
    cout << ">>> Clic sur bouton NewProject <<<" << endl;
    Garage::getInstance().resetCurrentProject();
    c = Garage::getInstance().getCurrentProject();
    clearTableOption();
    clearTableClients();
    clearTableContracts();
    clearTableEmployees();
    clearComboBoxAvailableModels();
    clearComboBoxAvailableOptions();
    setPrice(0);
    setModel("---", 0, 0, float(0), "---");
    setCurrentProjectName("---");
    auto &garage = Garage::getInstance();

    garage.importModelsFromCsv(CSV);
    garage.importOptionsFromCsv(CSV);
    int i = 0;

    do
    {
        Model m = garage.getModel(i);
        i++;
        if (m.getImage().empty())
        {
            break;
        }
        addAvailableModel(m.getName(), m.getBasePrice());
    } while(true);

    // Importation des options (étape 10)
    clearTableOption();
    i = 0;

    do
    {
        Option o = garage.getOption(i);
        i++;
        if (o.getLabel().empty())
        {
            break;
        }
        addAvailableOption(o.getLabel(), o.getPrice());
    } while(true);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonNewContract_clicked()
{
    // TO DO (étape 13)
    auto& garage = Garage::getInstance();   
    auto& contracts = garage.getContracts();
    Employee e = garage.findEmployeeById(garage.getId());
    int id = getIndexClientSelectionTable();
    if (id == -1)
    {
        dialogError("Erreur", "Erreur de selection");
        return;
    }
    Client cl = garage.findClientByIndex(id);
    if(e.getRole() == Employee::SELLER)
    {
        Contract co;
        string name = e.getLastName() + " " + e.getFirstName();
        string clientname = cl.getLastName() + " " + cl.getFirstName();
        co.setSeller(name);
        co.setClient(clientname);
        co.setId(Contract::currentId);
        string project = getCurrentProjectName();
        if(project == "")
        {
            dialogError("Erreur Saisie", "Vous n'avez rien saisie dans le nom du projet");
            return;
        }
        co.setProjectName(project);
        garage.addContract(co.getId(), co.getSeller(), co.getClient(), co.getProjectName());
        clearTableContracts();
        for(auto it = contracts.cbegin(); it != contracts.cend(); ++it)
        {
            addTupleTableContracts(it->tuple());

        }
    }
    else
    {
        dialogError("Erreur login", "Vous ne pouvez pas acceder a ceci");
    }
    cout << ">>> Clic sur bouton NewContract <<<" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonDeleteContract_clicked()
{
    // TO DO (étape 13)
    int indice = getIndexContractSelectionTable();
    if (indice == -1)
    {
        dialogError("Supprimer Contract (SELECTION)", "Erreur, vous n'avez rien selectionné");
        return;
    }
    auto& garage = Garage::getInstance();
    Contract co = garage.findContractByIndex(indice);
    int ok = c.compare(co.getProjectName());
    if (ok == 1)
    {
        dialogError("Supprimer Contract (CONTRAT EXISTANT)", "Erreur, vous ne pouvez pas supprimer un contrat validé");
        return;
    }
    
    auto& contracts = garage.getContracts();
    garage.deleteContractByIndex(indice);
    clearTableContracts();
    for(auto it = contracts.cbegin(); it != contracts.cend(); ++it)
    {
        addTupleTableContracts(it->tuple());

    }
    cout << ">>> Clic sur bouton DeleteContract <<<" << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicGarageWindow::on_pushButtonShowCar_clicked()
{
    // TO DO (étape 13)
    int indice = getIndexContractSelectionTable();
    if (indice == -1)
    {
        dialogError("Erreur Projet", "Le nom du projet est vide (Il n'y a pas de contrat selectionné)");
        return;
    }
    auto& garage = Garage::getInstance();
    Contract cl = garage.findContractByIndex(indice);
    string projectName = cl.getProjectName();

    c.load(projectName);
    // Model
    Model m = c.getModel();
    setModel(string(m.getName()), m.getPower(), m.getEngine(), m.getBasePrice(), m.getImage());
    // Option
    for (int i = 0; i < 5; i++)
    {
        Option* o = c[i];
        if (o != nullptr)
        {
            setTableOption(i, o->getCode(), o->getLabel(), o->getPrice());
        }
        else
        {
            setTableOption(i);
        }
    }
    setPrice(c.getPrice());
    setCurrentProjectName(projectName);
    cout << ">>> Clic sur bouton ShowCar <<<" << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Mes méthodes à moi /////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void ApplicGarageWindow::MAJtableOptions()
{
    for (int i=0 ; i<5 ; i++)
    {
        Option *ptr = Garage::getProjetEnCours()[i];
        if (ptr != NULL) setTableOption(i,ptr->getCode(),ptr->getLabel(),ptr->getPrice());
        else setTableOption(i);
    }
}

void ApplicGarageWindow::MAJprojetEnCours()
{
    setCurrentProjectName(Garage::getProjetEnCours().getName());
    setModel(Garage::getProjetEnCours().getModele().getName(),
              Garage::getProjetEnCours().getModele().getPower(),
              Garage::getProjetEnCours().getModele().getEngine(),
              Garage::getProjetEnCours().getModele().getBasePrice(),
              Garage::getProjetEnCours().getModele().getImage());
    MAJtableOptions();
    setPrice(Garage::getProjetEnCours().getPrice());
}

void ApplicGarageWindow::MAJtableEmployes()
{
    videTableEmployes();
    VecteurTrie<Employe> employes = Garage::getInstance().getEmployes();
    Iterateur<Employe> it(employes);
    while (!it.end())
    {
        addTupleTableEmployees(((Employe)it).Tuple());
        it++;
    }
}

void ApplicGarageWindow::MAJtableClients()
{
    videTableClients();
    VecteurTrie<Client> clients = Garage::getInstance().getClients();
    Iterateur<Client> it(clients);
    while (!it.end())
    {
        ajouteTupleTableClients(((Client)it).Tuple());
        it++;
    }
}

void ApplicGarageWindow::MAJtableContrats()
{
    videTableContrats();
    Vecteur<Contrat> contrats = Garage::getInstance().getContrats();
    Iterateur<Contrat> it(contrats);
    while (!it.end())
    {
        ajouteTupleTableContrats(((Contrat)it).Tuple());
        it++;
    }
}
*/


