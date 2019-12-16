#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   /* ui->setupUi(this);

    // TODO: Create state machine:
    auto stateMachine = new QStateMachine(this);

    // TODO: Create states:
    auto greenState = new QState(stateMachine);
    auto yellowState = new QState(stateMachine);
    auto redState = new QState(stateMachine);
    auto logState = new QState(stateMachine);

    // TODO: Set appropriate 'assignProperty'
    greenState->assignProperty(ui->pbToggle, "text", "GREEN");
    yellowState->assignProperty(ui->pbToggle, "text", "YELLOW");
    redState->assignProperty(ui->pbToggle, "text", "RED");

    // TODO: Set state transitions including this class events and slots
    greenState->addTransition(ui->pbToggle, SIGNAL(clicked()), redState);
    redState->addTransition(ui->pbToggle, SIGNAL(clicked()), yellowState);
    yellowState->addTransition(ui->pbToggle, SIGNAL(clicked()), logState);
    logState->addTransition(this, SIGNAL(done()), greenState);
    // TODO: make function log() works:
    connect(logState, SIGNAL(entered()), this, SLOT(log()));

    // TODO: Set initial state
    stateMachine->setInitialState(greenState);

    // TODO: Start state machine
    stateMachine->start();
    */
    ui->setupUi(this);

    auto stateMachine = new QStateMachine(this);

    auto unlockedState = new QState(stateMachine);
    auto startupState = new QState(unlockedState);
    auto openState = new QState(unlockedState);
    auto errorState = new QState(unlockedState);
    auto viewState = new QState(unlockedState);
    auto editState = new QState(unlockedState);
    auto lockedState = new QState(stateMachine);
    auto saveState = new QState(unlockedState);

    unlockedState->assignProperty(ui->pbToggle, "text", "Lock");
    unlockedState->assignProperty(ui->pbOpen, "enabled", true);
    unlockedState->assignProperty(ui->pbSave, "enabled", true);
    unlockedState->assignProperty(ui->teText, "enabled", true);

    startupState->assignProperty(ui->pbOpen, "enabled", true);
    startupState->assignProperty(ui->pbSave, "enabled", false);
    startupState->assignProperty(ui->teText, "enabled", false);
    startupState->assignProperty(ui->teText, "palceholderText", "Open file to start editing...");

    errorState->assignProperty(ui->pbOpen, "enabled", true);
    errorState->assignProperty(ui->pbSave, "enabled", false);
    errorState->assignProperty(ui->teText, "enabled", false);
    errorState->assignProperty(ui->teText, "palceholderText", "Error ocured. Open file to start editing...");

    viewState->assignProperty(ui->pbOpen, "enabled", true);
    viewState->assignProperty(ui->pbSave, "enabled", false);
    viewState->assignProperty(ui->teText, "enabled", true);

    editState->assignProperty(ui->pbOpen, "enabled", false);
    editState->assignProperty(ui->pbSave, "enabled", true);
    editState->assignProperty(ui->teText, "enabled", true);

    lockedState->assignProperty(ui->pbToggle, "text", "Unlock");
    lockedState->assignProperty(ui->pbOpen, "enabled", false);
    lockedState->assignProperty(ui->pbSave, "enabled", false);
    lockedState->assignProperty(ui->teText, "enabled", false);

    startupState->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), openState);

    openState->addTransition(this, SIGNAL(opened()), viewState);
    openState->addTransition(this, SIGNAL(error()), errorState);

    viewState->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), openState);
    viewState->addTransition(ui->teText,SIGNAL(textChanged()), editState);

    editState->addTransition(ui->pbSave, SIGNAL(clicked(bool)), saveState);

    saveState->addTransition(this, SIGNAL(saved()), viewState);
    saveState->addTransition(this, SIGNAL(error()), errorState);

    errorState->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), openState);
    unlockedState->addTransition(ui->pbToggle, SIGNAL(clicked(bool)), lockedState);

    lockedState->addTransition(ui->pbToggle,SIGNAL(clicked(bool)), errorState);

    connect(openState, SIGNAL(entered()),this, SLOT(open()));
    connect(saveState, SIGNAL(entered()),this, SLOT(save()));

    stateMachine->setInitialState(unlockedState);
    unlockedState->setInitialState(startupState);
    stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    // TODO: Show file dialog
    fileName =  QFileDialog::getOpenFileName(this, tr("Open File"));
    if(fileName.isEmpty())
        emit error();
    else {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadWrite|QFile::Text)){
            emit error();
        }
        else{
            ui->teText->setText(file.readAll());
            emit opened();
        }
    }
    // TODO: Open selected file
    // TODO: Emit 'error' if opening failed
    // TODO: Set text and emit 'opened' if suceeded
    // TODO: Save file name in 'fileName'
}

void MainWindow::save()
{
    // TODO: Open 'fileName' for writing
    // TODO: Emit 'error' if opening failed
    // TODO: Save file and emit 'saved' if succeeded
    if(fileName.isEmpty())
        emit error();
    else {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadWrite| QIODevice::Append |QFile::Text)){
            emit error();
        }
        else{
            //ui->teText->setText(file.readAll());

            QTextStream stream( &file );

            emit saved();
        }
    }
}

void MainWindow::log()
{
    qDebug() << "Inside log() function...";
    emit done();
}
