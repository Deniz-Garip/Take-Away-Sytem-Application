#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QInputDialog>
#include <QStackedWidget>
#include <QLabel>
#include <QListWidget>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    setupMenu();
    main();
    Clour();
}

MainWindow::~MainWindow(){}
void MainWindow::setupMenu() // name, quantity,price cuisine
{
    menu_item =
        {
         {"Gryous",10,13,"Greece"},
         {"Lamb Souvlaki",10,13, "Greece"},
         {"Dolmadakia",10, 14,"Greece"},
         {"Grilled Octopus",10,10, "Greece"},
         {"Makaronia tou Fournou", 10,8, "Cyprus"},
         {"Sheftalies",10, 14,"Cyprus"},
         {"Koubes", 10,12, "Cyprus"},
         {"Ofto Kleftiko",10,15,"Cyprus"},
         };
}

void MainWindow::main()
{
    setWindowTitle("Main Menu");
    setFixedSize(800, 600);

    QWidget *main = new QWidget(this);
    QVBoxLayout *main_loyalt = new QVBoxLayout(main);
    setCentralWidget(main);



    QLabel *title_main = new QLabel("Main Menu", this);
    title_main->setAlignment(Qt::AlignCenter);
    title_main->setObjectName("title_main");
    main_loyalt->addWidget(title_main);


    QGroupBox *password_box = new QGroupBox(this);
    QHBoxLayout *password_layout = new QHBoxLayout(password_box);

    paswword_input = new QLineEdit(this);
    paswword_input->setPlaceholderText("Enter the password");
    paswword_input->setEchoMode(QLineEdit::Password);

    password_layout->addWidget(new QLabel("Password", this));
    password_layout->addWidget(paswword_input);
    main_loyalt->addWidget(password_box);


    QGroupBox   *buttons = new QGroupBox(this);
    QHBoxLayout *buttons_layout = new QHBoxLayout(buttons);

    boss_button = new QPushButton("Access the Boss System", this);
    boss_button->setObjectName("boss_button");
    buttons_layout->addWidget(boss_button);
    main_loyalt->addWidget(buttons);

    QGroupBox   *box = new QGroupBox(this);
    QHBoxLayout *box_layout = new QHBoxLayout(box);

    customer_button = new QPushButton("Access the Customer System", this);
    customer_button->setObjectName("customer_button");
    box_layout->addWidget(customer_button);
    main_loyalt->addWidget(box);

    connect(boss_button,     &QPushButton::clicked, this, &MainWindow::Boss);
    connect(customer_button, &QPushButton::clicked, this, &MainWindow::Customer);
}


void MainWindow::Customer()
{
    setupUI();
}

void MainWindow::Boss()
{


    if(paswword_input->text().toInt()!=password)
    {
        QMessageBox::warning(this,"Incorrect password","Incorrect password "+paswword_input->text()+" try again");
        return;
    }

    if(paswword_input->text().toInt() ==password)
    {
        QMessageBox::information(this,"Password ","Password is correct");


    setWindowTitle("Boss page");
    setFixedSize(800,600);

     QWidget *main = new QWidget(this);
    QVBoxLayout *main_layout = new QVBoxLayout(main);
     setCentralWidget(main);



        QLabel  *boss_title = new QLabel("Boss system",this);
        boss_title->setAlignment(Qt::AlignCenter);
        boss_title->setObjectName("boss_title");
        main_layout->addWidget(boss_title);


    QGroupBox *add = new QGroupBox(this);
        QHBoxLayout *add_layout = new QHBoxLayout(add);

    add_newitem = new QPushButton("Add the meal on the menu",this);
        add_newitem->setObjectName("add_newitem");

    add_layout->addWidget(add_newitem);
        main_layout->addWidget(add);

    QGroupBox *delet = new QGroupBox(this);
        QHBoxLayout *delet_layout = new QHBoxLayout(delet);

    item_delet = new QPushButton("delet the meal on the menu",this);
        item_delet->setObjectName("item_delet");

    delet_layout->addWidget(item_delet);
        main_layout->addWidget(delet);

    QGroupBox *check=new QGroupBox(this);
        QHBoxLayout *check_layout = new QHBoxLayout(check);

    item_check = new QPushButton("Check the meal on the menu",this);
        item_check->setObjectName("item_check");

    check_layout->addWidget(item_check);
        main_layout->addWidget(check);

    connect(add_newitem, &QPushButton::clicked,this,&MainWindow::add_new_add);
    connect(item_delet,&QPushButton::clicked,this,&MainWindow::delet_item);
    connect(item_check,&QPushButton::clicked,this,&MainWindow::check_item);


    }
}

void MainWindow::add_new_add()
{
    bool ok;

    QString meal_name = QInputDialog::getText(this,"New meal","Enter new meal",QLineEdit::Normal,"",&ok);

    if(!ok || meal_name.isEmpty())
        return;

    int quantity = QInputDialog::getInt(this,"New meal","Enter new meal quantity",1,1,999,1,&ok);
    if(!ok) return;

    double price = QInputDialog::getDouble(this,"New meal","Enter new meal price",0,0,999,1,&ok);
    if(!ok) return;

    QStringList cuisines;
    cuisines << "Greece" << "Cyprus" << "Other";
    QString cuisine = QInputDialog::getItem(this,"New meal","Enter new meal cuisine",cuisines, 0, false,&ok);
    if(!ok) return;

    menu_item.push_back({meal_name,quantity, (float)price,cuisine});

    QString enter = QString("%1, %2, %£3, (%4),%5")
        .arg(menu_item.size())
        .arg(meal_name)
        .arg(quantity)
        .arg(price)
        .arg(cuisine);

    menu_list->addItem(enter);

    QMessageBox::information(this,"working","working");

}
void MainWindow::delet_item()
{
    bool ok;
    int number = QInputDialog::getInt(this, "Delete Meal",
                                      "Enter meal number to delete (1-" +
                                          QString::number(menu_item.size()) + "):",
                                      1, 1, menu_item.size(), 1, &ok);
    if(!ok) return;

    menu_list->clear();
    for(int i = 0; i < menu_item.size(); i++)
    {
        QString enter = QString("%1. %2, Qty:%3, £%4, (%5)")
                            .arg(i + 1)
                            .arg(menu_item[i].meal_name)
                            .arg(menu_item[i].quantity)
                            .arg(menu_item[i].price)
                            .arg(menu_item[i].cuisine);
        menu_list->addItem(enter);
    }

    // Step 7 — Confirm deleted
    QMessageBox::information(this, "Deleted!", " has been removed from the menu!");

}

void MainWindow::check_item()
{
    QMessageBox::information(this,"Working","Working");

    QString ouput;
    ouput +="--------------\n";
    for(int i=0;i<menu_item.size();i++)
    {
        ouput += QString("%1,%2,qty:%3,%4,%5\n")
                        .arg(i+1)
                       .arg(menu_item[i].meal_name)
                       .arg(menu_item[i].quantity)
                        .arg(menu_item[i].price)
                       .arg(menu_item[i].cuisine);

    }
    ouput +="--------------\n";
    QMessageBox::information(this,"Working",ouput);

}





void MainWindow::setupUI()
{
    setWindowTitle("Take Away System");
    setFixedSize(800,600);

    QWidget *central = new QWidget(this);
    QVBoxLayout *mainloayt = new QVBoxLayout(central);
    setCentralWidget(central);

    //title
    QLabel *title = new QLabel("Take Away",this);
    title-> setAlignment(Qt::AlignCenter);
    title->setObjectName("title");
    mainloayt->addWidget(title);


    QGroupBox *infoBox = new QGroupBox("Information for people",this);
    QHBoxLayout *infoLayout = new QHBoxLayout(infoBox);

    name_input = new QLineEdit(this);
    address_input = new QLineEdit(this);
    phone_input = new QLineEdit(this);



    name_input->setPlaceholderText("Your Name");
    address_input->setPlaceholderText("Your address");
    phone_input->setPlaceholderText("Phone Number");


    infoLayout->addWidget(new QLabel("Name",this));
    infoLayout->addWidget(name_input);
    infoLayout->addWidget(new QLabel("Address",this));
    infoLayout->addWidget(address_input);
    infoLayout->addWidget(new QLabel("Phone number",this));
    infoLayout->addWidget(phone_input);

    mainloayt->addWidget(infoBox);

    menu_list = new QListWidget(this);
    menu_list->setObjectName("menu_list");

    QHBoxLayout * main = new QHBoxLayout();

    QGroupBox *left_menu = new QGroupBox(this);
    QHBoxLayout * menu = new QHBoxLayout(left_menu);


    for(int i =0; i<menu_item.size();i++)
    {
        QString enter = QString ("%1 , %2 = %3, (%4)")
            .arg(i +1)
                            .arg(menu_item[i].meal_name)
                            .arg(menu_item[i].price)
                            .arg(menu_item[i].cuisine);
        menu_list->addItem(enter);

    }

    add_button = new QPushButton("add to Basket",this);
    add_button ->setObjectName("add_button");

    menu->addWidget(add_button);
        main->addWidget(left_menu);
    menu->addWidget(menu_list);

    // left basket

    QGroupBox *left_basket = new QGroupBox("Baket",this);
    QVBoxLayout *basket_layoyt = new QVBoxLayout(left_basket);

    basket_list = new QListWidget(this);
    basket_list-> setObjectName("basket_list");


    total_label = new QLabel("total: ",this);
    total_label->setAlignment(Qt::AlignRight);
    total_label->setObjectName("total_label");

    placed_button = new QPushButton("order",this);
    placed_button->setObjectName("placed_button");
    clear_button = new QPushButton("Clear",this);
    clear_button->setObjectName("clear_button");


    basket_layoyt->addWidget(basket_list);
    basket_layoyt->addWidget(total_label);
    basket_layoyt->addWidget(placed_button);
    basket_layoyt->addWidget(clear_button);
    main->addWidget(left_basket);

    mainloayt->addLayout(main);

    connect(add_button,&QPushButton::clicked,this,&MainWindow::add_item);
    connect(placed_button, &QPushButton::clicked,this,&MainWindow::Placed);
    connect(clear_button,&QPushButton::clicked,this,&MainWindow::Clear);


}

void MainWindow::add_item()
{
    int add = menu_list->currentRow();
    if (add < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a menu item first!");
        return;
    }

    if(menu_item[add].quantity<=0)
    {
        QMessageBox::warning(this,"Out of Stock", menu_item[add].meal_name+"is not available");
        return;
    }

    int qty= QInputDialog::getInt(this,"Quantity","How many" + menu_item[add].meal_name +"do you want",1,1,10,1);

    menu_item[add].quantity -=qty;

    bool find = false;
    for(auto &item: baket_item)
    {
        if(item.meal_name == menu_item[add].meal_name)
        {
            item.quantity +=qty;
            find = true;
            break;
        }

    }

    if(!find)
    {
        baket_item.push_back({menu_item[add].meal_name,menu_item[add].price,qty});
    }

    calculate_price_to_basket();
    total_resul();
}



void MainWindow::calculate_price_to_basket()
{
    basket_list->clear();
    for(const auto &item:baket_item)
    {   QString line = QString{"%1 || %2 = £%3"}
        .arg(item.meal_name)
        .arg(item.quantity)
                           .arg(item.quantity *item.price);
        basket_list->addItem(line);

    }
}

void MainWindow:: total_resul()
{

    for(const auto &item:baket_item)
    {
        total +=item.price * item.quantity;
    }
    total_label->setText(QString("Total: £1%").arg(total));

}



void MainWindow::Placed()
{
    if(baket_item.empty())
    {
        QMessageBox::warning(this,"Baket","Your basket is empty!");
            return;
    }
    if(name_input->text().isEmpty() ||phone_input->text().isEmpty() || address_input->text().isEmpty())
    {
        QMessageBox::warning(this,"Personal Deatils is empty","Personal deatils is empty please fill up");
        return;
    }
    QString summary = "Bill\n";
    summary += "------------------\n";
    summary += "Name:         " + name_input->text()    + "\n";
    summary += "Phone Number: " + phone_input->text()   + "\n";
    summary += "Address:      " + address_input->text() + "\n";
    summary += "------------------\n";

    for(const auto &item : baket_item)
    {
        // ✅ quantity not price, \n at end
        summary += QString("%1 x%2 = £%3\n")
                       .arg(item.meal_name)
                       .arg(item.quantity)
                       .arg(item.price * item.quantity, 0, 'f', 2);
    }

    summary += "------------------\n";
    summary += QString("Total: £%1\n").arg(total, 0, 'f', 2);
    summary += "------------------\n";

    // ✅ Show the popup!
    QMessageBox::information(this, "Order Placed!", summary);

    Clear();
}

void MainWindow::Clear()
{
    basket_list->clear();
    baket_item.clear();
    total =0;
    total_label->setText("Total:£0");
}

void MainWindow::Clour()
{
    this->setStyleSheet(R"(

        QMainWindow {
            background-color: #0a192f;
        }

        QWidget {
            background-color: #0a192f;
            color: #ccd6f6;
            font-family: Arial;
            font-size: 13px;
        }

        QGroupBox {
            border: 2px solid #64ffda;
            border-radius: 8px;
            margin-top: 10px;
            padding: 10px;
            font-size: 14px;
            font-weight: bold;
            color: #64ffda;
        }

        QLabel#title {
            font-size: 26px;
            font-weight: bold;
            color: #64ffda;
            padding: 10px;
        }

        QLabel#total_label {
            font-size: 16px;
            font-weight: bold;
            color: #f6c90e;
            padding: 5px;
        }

        QListWidget {
            background-color: #112240;
            border: 1px solid #64ffda;
            border-radius: 6px;
            color: #ccd6f6;
            font-size: 13px;
            padding: 5px;
        }

        QListWidget::item:selected {
            background-color: #64ffda;
            color: #0a192f;
            border-radius: 4px;
        }

        QListWidget::item:hover {
            background-color: #1e3a5f;
        }

        QLineEdit {
            background-color: #112240;
            border: 1px solid #64ffda;
            border-radius: 5px;
            color: #ccd6f6;
            padding: 5px;
        }

        QLineEdit:focus {
            border: 1px solid #f6c90e;
        }

        QPushButton#add_button {
            background-color: #112240;
            color: #64ffda;
            border: 2px solid #64ffda;
            border-radius: 8px;
            padding: 10px;
            font-size: 14px;
            font-weight: bold;
        }

        QPushButton#add_button:hover {
            background-color: #64ffda;
            color: #0a192f;
        }

        QPushButton#placed_button {
            background-color: #f6c90e;
            color: #0a192f;
            border-radius: 8px;
            padding: 10px;
            font-size: 14px;
            font-weight: bold;
        }

        QPushButton#placed_button:hover {
            background-color: #ffe066;
            color: #0a192f;
        }

        QPushButton#clear_button {
            background-color: #112240;
            color: #64ffda;
            border: 2px solid #64ffda;
            border-radius: 8px;
            padding: 10px;
            font-size: 14px;
            font-weight: bold;
        }

        QPushButton#clear_button:hover {
            background-color: #64ffda;
            color: #0a192f;
        }

        QInputDialog {
            background-color: #0a192f;
            color: #ccd6f6;
        }

        QMessageBox {
            background-color: #0a192f;
            color: #ccd6f6;
        }

    )");
}
