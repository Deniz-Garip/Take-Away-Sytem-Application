#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QLineEdit>
#include <QMessageBox>
#include <vector>
#include <QStackedWidget>


using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:

    void Customer();
    void Boss();
    void Placed();
    void Clear();
    void add_item();
    void check_item();
   void delet_item();
    void add_new_add();

    private:

        //Buttons
        QPushButton *add_button;
        QPushButton *clear_button;
        QPushButton *placed_button;
        QPushButton *customer_button;
        QPushButton *boss_button;
        QPushButton *add_newitem;
        QPushButton *item_check;
        QPushButton *item_delet;

        //Label
        QLabel *total_label;


        // Line Edit

        QLineEdit * name_input;
        QLineEdit * address_input;
        QLineEdit * phone_input;
        QLineEdit * paswword_input;

        //ListWidget

        QListWidget *menu_list;
        QListWidget *basket_list;

        //struct
        struct Menu_Item
        {
            QString meal_name;
            int quantity;
            float price;
            QString cuisine;

        };

        struct Baket_Item
        {
             QString meal_name;
            float price;
             int quantity;
        };





        std::vector<Menu_Item> menu_item;
        std::vector<Baket_Item> baket_item;

        float total;
        int password =123;
        int number;




        void setupMenu();
        void setupUI();
        void calculate_price_to_basket();
        void total_resul();
        void Clour();
        void main();
        void setupBoss();
        void setupCustomer();




    private:
        QStackedWidget *pages;    // holds all pages
        QWidget        *page_main;      // main menu page
        QWidget        *page_boss;      // boss page
        QWidget        *page_customer;  // customer page



};
#endif
