#include "mainwindow.h"
#include "numbersfile.cpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTextBrowser(string name)
{
    ifstream i_file(name, ios::binary);
    size_t num;
    string s = "";
    i_file.read((char*)&num, sizeof(size_t));
    do{
        s += to_string(num)+" ";
        i_file.read((char*)&num, sizeof(size_t));
    }while(!i_file.eof());
    ui->fileTextBrowser->setText(QString::fromStdString(s));
    i_file.close();
}

void MainWindow::on_saveButton_clicked()
{
    string name = ui->fileNameLineEdit->text().toStdString();
    size_t size = (size_t)ui->fileSizeLineEdit->text().toInt();
    NumbersFile nfile(name, size);
    bool res = nfile.insertRange((size_t)ui->startLineEdit->text().toInt(),(size_t)ui->endLineEdit->text().toInt(), (size_t)ui->powerLineEdit->text().toInt());
    if(res)
        updateTextBrowser(name);

}

void MainWindow::on_findButton_clicked()
{
    if(ui->findLineEdit->text().isEmpty()){
        MessageBoxA(NULL, (char*)"Enter element to find!", (char*)"Error", MB_ICONINFORMATION);
        return;
    }
    try{

        ifstream i_file(ui->fileNameLineEdit->text().toStdString(), ios::binary);
        if(i_file.is_open())
        {
            size_t num;
            int position = 1;
            i_file.read((char*)&num, sizeof(size_t));
            do{
                if(ui->findLineEdit->text().toInt() == num)
                {
                    string message = "Element was found at position " + to_string(position);
                    MessageBoxA(NULL, message.c_str(), (char*)"Success", MB_ICONINFORMATION);
                    i_file.close();
                    return;
                }
                position++;
                i_file.read((char*)&num, sizeof(size_t));
            }while(!i_file.eof());
            i_file.close();
            throw NotFoundException();
        }
    }
    catch(NotFoundException e){
        MessageBoxA(NULL, e.what(), (char*)"Error", MB_ICONWARNING);
    }

}

