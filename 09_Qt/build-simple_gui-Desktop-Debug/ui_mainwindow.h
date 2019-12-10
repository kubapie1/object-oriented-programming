/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit;
    QLCDNumber *lcdNumberSpeed;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit_2;
    QLCDNumber *lcdNumberAcceleration;
    QLineEdit *lineEditDisplacement;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(396, 337);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 0, 316, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(150, 30));
        textEdit->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setKerning(true);
        textEdit->setFont(font);
        textEdit->setFrameShape(QFrame::VLine);
        textEdit->setReadOnly(true);

        horizontalLayout->addWidget(textEdit);

        lcdNumberSpeed = new QLCDNumber(layoutWidget);
        lcdNumberSpeed->setObjectName(QString::fromUtf8("lcdNumberSpeed"));
        lcdNumberSpeed->setMaximumSize(QSize(150, 30));

        horizontalLayout->addWidget(lcdNumberSpeed);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        textEdit_2 = new QTextEdit(layoutWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setMaximumSize(QSize(150, 30));
        textEdit_2->setFrameShape(QFrame::VLine);
        textEdit_2->setFrameShadow(QFrame::Sunken);
        textEdit_2->setLineWidth(0);
        textEdit_2->setMidLineWidth(0);
        textEdit_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        textEdit_2->setLineWrapMode(QTextEdit::WidgetWidth);
        textEdit_2->setLineWrapColumnOrWidth(0);
        textEdit_2->setReadOnly(true);

        horizontalLayout_2->addWidget(textEdit_2);

        lcdNumberAcceleration = new QLCDNumber(layoutWidget);
        lcdNumberAcceleration->setObjectName(QString::fromUtf8("lcdNumberAcceleration"));
        lcdNumberAcceleration->setMaximumSize(QSize(150, 30));

        horizontalLayout_2->addWidget(lcdNumberAcceleration);


        verticalLayout->addLayout(horizontalLayout_2);

        lineEditDisplacement = new QLineEdit(layoutWidget);
        lineEditDisplacement->setObjectName(QString::fromUtf8("lineEditDisplacement"));
        lineEditDisplacement->setCursorPosition(0);
        lineEditDisplacement->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(lineEditDisplacement);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 396, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Speed</p></body></html>", nullptr));
        textEdit_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Acceleration</p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Change", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
