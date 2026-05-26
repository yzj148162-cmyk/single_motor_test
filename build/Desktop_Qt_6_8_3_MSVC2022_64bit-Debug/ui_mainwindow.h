/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *rootLayout;
    QHBoxLayout *topLayout;
    QVBoxLayout *leftLayout;
    QGroupBox *motionGroupBox;
    QFormLayout *motionFormLayout;
    QLabel *axisLabel;
    QSpinBox *axisSpin;
    QLabel *modeLabel;
    QComboBox *modeCombo;
    QLabel *deltaAngleLabel;
    QDoubleSpinBox *deltaAngleSpin;
    QLabel *durationLabel;
    QDoubleSpinBox *durationSpin;
    QLabel *systemPlanningPeriodLabel;
    QSpinBox *systemPlanningPeriodMsSpin;
    QLabel *minVelLabel;
    QDoubleSpinBox *minVelSpin;
    QLabel *maxVelLabel;
    QDoubleSpinBox *maxVelSpin;
    QLabel *trajectoryShapeLabel;
    QComboBox *trajectoryShapeCombo;
    QLabel *sineAmplitudeLabel;
    QDoubleSpinBox *sineAmplitudeSpin;
    QLabel *sineOmegaLabel;
    QDoubleSpinBox *sineOmegaSpin;
    QLabel *reciprocatingLabel;
    QCheckBox *reciprocatingCheck;
    QGroupBox *displayGroupBox;
    QFormLayout *displayFormLayout;
    QLabel *uiRefreshLabel;
    QSpinBox *uiRefreshMsSpin;
    QGroupBox *cspRuntimeGroupBox;
    QFormLayout *cspRuntimeFormLayout;
    QLabel *ecatPortLabel;
    QSpinBox *ecatPortSpin;
    QLabel *nodeLabel;
    QSpinBox *nodeSpin;
    QLabel *cspInterpPeriodMsLabel;
    QSpinBox *cspInterpPeriodMsSpin;
    QLabel *cspInterpIndexLabel;
    QSpinBox *cspInterpIndexSpin;
    QGroupBox *advancedGroupBox;
    QFormLayout *advancedFormLayout;
    QLabel *positionUnitLabel;
    QHBoxLayout *positionUnitLayout;
    QRadioButton *degreeUnitRadio;
    QRadioButton *turnUnitRadio;
    QLabel *cspRxpdoPosAddrLabel;
    QSpinBox *cspRxpdoPosAddrSpin;
    QLabel *cspTxpdoStatusAddrLabel;
    QSpinBox *cspTxpdoStatusAddrSpin;
    QLabel *cspTxpdoModeAddrLabel;
    QSpinBox *cspTxpdoModeAddrSpin;
    QLabel *cspTxpdoPosAddrLabel;
    QSpinBox *cspTxpdoPosAddrSpin;
    QVBoxLayout *rightLayout;
    QGroupBox *buttonBox;
    QGridLayout *buttonLayout;
    QPushButton *initCardButton;
    QPushButton *closeCardButton;
    QPushButton *enableAxisButton;
    QPushButton *disableAxisButton;
    QPushButton *readPosButton;
    QPushButton *stopButton;
    QPushButton *startButton;
    QGroupBox *statusBox;
    QFormLayout *statusLayout;
    QLabel *connectionTextLabel;
    QLabel *connectionLabel;
    QLabel *positionTextLabel;
    QLabel *positionLabel;
    QLabel *stateTextLabel;
    QLabel *stateLabel;
    QLabel *queueTextLabel;
    QLabel *queueLabel;
    QLabel *cycleTextLabel;
    QLabel *cycleLabel;
    QLabel *errorTextLabel;
    QLabel *errorLabel;
    QLabel *traceStatusTextLabel;
    QLabel *traceStatusLabel;
    QGroupBox *tipBox;
    QVBoxLayout *tipLayout;
    QLabel *tipLabel;
    QWidget *errorPlotHost;
    QPlainTextEdit *logEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1180, 920);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        rootLayout = new QVBoxLayout(centralwidget);
        rootLayout->setObjectName("rootLayout");
        topLayout = new QHBoxLayout();
        topLayout->setObjectName("topLayout");
        leftLayout = new QVBoxLayout();
        leftLayout->setObjectName("leftLayout");
        motionGroupBox = new QGroupBox(centralwidget);
        motionGroupBox->setObjectName("motionGroupBox");
        motionFormLayout = new QFormLayout(motionGroupBox);
        motionFormLayout->setObjectName("motionFormLayout");
        axisLabel = new QLabel(motionGroupBox);
        axisLabel->setObjectName("axisLabel");

        motionFormLayout->setWidget(0, QFormLayout::LabelRole, axisLabel);

        axisSpin = new QSpinBox(motionGroupBox);
        axisSpin->setObjectName("axisSpin");
        axisSpin->setMaximum(63);

        motionFormLayout->setWidget(0, QFormLayout::FieldRole, axisSpin);

        modeLabel = new QLabel(motionGroupBox);
        modeLabel->setObjectName("modeLabel");

        motionFormLayout->setWidget(1, QFormLayout::LabelRole, modeLabel);

        modeCombo = new QComboBox(motionGroupBox);
        modeCombo->setObjectName("modeCombo");

        motionFormLayout->setWidget(1, QFormLayout::FieldRole, modeCombo);

        deltaAngleLabel = new QLabel(motionGroupBox);
        deltaAngleLabel->setObjectName("deltaAngleLabel");

        motionFormLayout->setWidget(2, QFormLayout::LabelRole, deltaAngleLabel);

        deltaAngleSpin = new QDoubleSpinBox(motionGroupBox);
        deltaAngleSpin->setObjectName("deltaAngleSpin");
        deltaAngleSpin->setMinimum(-999999.000000000000000);
        deltaAngleSpin->setMaximum(999999.000000000000000);
        deltaAngleSpin->setDecimals(3);
        deltaAngleSpin->setValue(300.000000000000000);

        motionFormLayout->setWidget(2, QFormLayout::FieldRole, deltaAngleSpin);

        durationLabel = new QLabel(motionGroupBox);
        durationLabel->setObjectName("durationLabel");

        motionFormLayout->setWidget(3, QFormLayout::LabelRole, durationLabel);

        durationSpin = new QDoubleSpinBox(motionGroupBox);
        durationSpin->setObjectName("durationSpin");
        durationSpin->setMinimum(0.050000000000000);
        durationSpin->setMaximum(3600.000000000000000);
        durationSpin->setDecimals(3);
        durationSpin->setValue(15.000000000000000);

        motionFormLayout->setWidget(3, QFormLayout::FieldRole, durationSpin);

        systemPlanningPeriodLabel = new QLabel(motionGroupBox);
        systemPlanningPeriodLabel->setObjectName("systemPlanningPeriodLabel");

        motionFormLayout->setWidget(4, QFormLayout::LabelRole, systemPlanningPeriodLabel);

        systemPlanningPeriodMsSpin = new QSpinBox(motionGroupBox);
        systemPlanningPeriodMsSpin->setObjectName("systemPlanningPeriodMsSpin");
        systemPlanningPeriodMsSpin->setMinimum(1);
        systemPlanningPeriodMsSpin->setMaximum(1000);
        systemPlanningPeriodMsSpin->setValue(10);

        motionFormLayout->setWidget(4, QFormLayout::FieldRole, systemPlanningPeriodMsSpin);

        minVelLabel = new QLabel(motionGroupBox);
        minVelLabel->setObjectName("minVelLabel");

        motionFormLayout->setWidget(5, QFormLayout::LabelRole, minVelLabel);

        minVelSpin = new QDoubleSpinBox(motionGroupBox);
        minVelSpin->setObjectName("minVelSpin");
        minVelSpin->setMaximum(100000.000000000000000);
        minVelSpin->setDecimals(3);

        motionFormLayout->setWidget(5, QFormLayout::FieldRole, minVelSpin);

        maxVelLabel = new QLabel(motionGroupBox);
        maxVelLabel->setObjectName("maxVelLabel");

        motionFormLayout->setWidget(6, QFormLayout::LabelRole, maxVelLabel);

        maxVelSpin = new QDoubleSpinBox(motionGroupBox);
        maxVelSpin->setObjectName("maxVelSpin");
        maxVelSpin->setMinimum(0.001000000000000);
        maxVelSpin->setMaximum(100000.000000000000000);
        maxVelSpin->setDecimals(3);
        maxVelSpin->setValue(60.000000000000000);

        motionFormLayout->setWidget(6, QFormLayout::FieldRole, maxVelSpin);

        trajectoryShapeLabel = new QLabel(motionGroupBox);
        trajectoryShapeLabel->setObjectName("trajectoryShapeLabel");

        motionFormLayout->setWidget(7, QFormLayout::LabelRole, trajectoryShapeLabel);

        trajectoryShapeCombo = new QComboBox(motionGroupBox);
        trajectoryShapeCombo->setObjectName("trajectoryShapeCombo");

        motionFormLayout->setWidget(7, QFormLayout::FieldRole, trajectoryShapeCombo);

        sineAmplitudeLabel = new QLabel(motionGroupBox);
        sineAmplitudeLabel->setObjectName("sineAmplitudeLabel");

        motionFormLayout->setWidget(8, QFormLayout::LabelRole, sineAmplitudeLabel);

        sineAmplitudeSpin = new QDoubleSpinBox(motionGroupBox);
        sineAmplitudeSpin->setObjectName("sineAmplitudeSpin");
        sineAmplitudeSpin->setMinimum(0.001000000000000);
        sineAmplitudeSpin->setMaximum(1000000.000000000000000);
        sineAmplitudeSpin->setDecimals(4);
        sineAmplitudeSpin->setValue(30.000000000000000);

        motionFormLayout->setWidget(8, QFormLayout::FieldRole, sineAmplitudeSpin);

        sineOmegaLabel = new QLabel(motionGroupBox);
        sineOmegaLabel->setObjectName("sineOmegaLabel");

        motionFormLayout->setWidget(9, QFormLayout::LabelRole, sineOmegaLabel);

        sineOmegaSpin = new QDoubleSpinBox(motionGroupBox);
        sineOmegaSpin->setObjectName("sineOmegaSpin");
        sineOmegaSpin->setMinimum(0.001000000000000);
        sineOmegaSpin->setMaximum(1000.000000000000000);
        sineOmegaSpin->setDecimals(4);
        sineOmegaSpin->setValue(1.000000000000000);

        motionFormLayout->setWidget(9, QFormLayout::FieldRole, sineOmegaSpin);

        reciprocatingLabel = new QLabel(motionGroupBox);
        reciprocatingLabel->setObjectName("reciprocatingLabel");

        motionFormLayout->setWidget(10, QFormLayout::LabelRole, reciprocatingLabel);

        reciprocatingCheck = new QCheckBox(motionGroupBox);
        reciprocatingCheck->setObjectName("reciprocatingCheck");

        motionFormLayout->setWidget(10, QFormLayout::FieldRole, reciprocatingCheck);


        leftLayout->addWidget(motionGroupBox);

        displayGroupBox = new QGroupBox(centralwidget);
        displayGroupBox->setObjectName("displayGroupBox");
        displayFormLayout = new QFormLayout(displayGroupBox);
        displayFormLayout->setObjectName("displayFormLayout");
        uiRefreshLabel = new QLabel(displayGroupBox);
        uiRefreshLabel->setObjectName("uiRefreshLabel");

        displayFormLayout->setWidget(0, QFormLayout::LabelRole, uiRefreshLabel);

        uiRefreshMsSpin = new QSpinBox(displayGroupBox);
        uiRefreshMsSpin->setObjectName("uiRefreshMsSpin");
        uiRefreshMsSpin->setMinimum(10);
        uiRefreshMsSpin->setMaximum(500);
        uiRefreshMsSpin->setValue(50);

        displayFormLayout->setWidget(0, QFormLayout::FieldRole, uiRefreshMsSpin);


        leftLayout->addWidget(displayGroupBox);

        cspRuntimeGroupBox = new QGroupBox(centralwidget);
        cspRuntimeGroupBox->setObjectName("cspRuntimeGroupBox");
        cspRuntimeFormLayout = new QFormLayout(cspRuntimeGroupBox);
        cspRuntimeFormLayout->setObjectName("cspRuntimeFormLayout");
        ecatPortLabel = new QLabel(cspRuntimeGroupBox);
        ecatPortLabel->setObjectName("ecatPortLabel");

        cspRuntimeFormLayout->setWidget(0, QFormLayout::LabelRole, ecatPortLabel);

        ecatPortSpin = new QSpinBox(cspRuntimeGroupBox);
        ecatPortSpin->setObjectName("ecatPortSpin");
        ecatPortSpin->setMaximum(8);
        ecatPortSpin->setValue(2);

        cspRuntimeFormLayout->setWidget(0, QFormLayout::FieldRole, ecatPortSpin);

        nodeLabel = new QLabel(cspRuntimeGroupBox);
        nodeLabel->setObjectName("nodeLabel");

        cspRuntimeFormLayout->setWidget(1, QFormLayout::LabelRole, nodeLabel);

        nodeSpin = new QSpinBox(cspRuntimeGroupBox);
        nodeSpin->setObjectName("nodeSpin");
        nodeSpin->setMinimum(1);
        nodeSpin->setMaximum(65535);
        nodeSpin->setValue(1);

        cspRuntimeFormLayout->setWidget(1, QFormLayout::FieldRole, nodeSpin);

        cspInterpPeriodMsLabel = new QLabel(cspRuntimeGroupBox);
        cspInterpPeriodMsLabel->setObjectName("cspInterpPeriodMsLabel");

        cspRuntimeFormLayout->setWidget(2, QFormLayout::LabelRole, cspInterpPeriodMsLabel);

        cspInterpPeriodMsSpin = new QSpinBox(cspRuntimeGroupBox);
        cspInterpPeriodMsSpin->setObjectName("cspInterpPeriodMsSpin");
        cspInterpPeriodMsSpin->setMinimum(1);
        cspInterpPeriodMsSpin->setMaximum(4);
        cspInterpPeriodMsSpin->setValue(1);

        cspRuntimeFormLayout->setWidget(2, QFormLayout::FieldRole, cspInterpPeriodMsSpin);

        cspInterpIndexLabel = new QLabel(cspRuntimeGroupBox);
        cspInterpIndexLabel->setObjectName("cspInterpIndexLabel");

        cspRuntimeFormLayout->setWidget(3, QFormLayout::LabelRole, cspInterpIndexLabel);

        cspInterpIndexSpin = new QSpinBox(cspRuntimeGroupBox);
        cspInterpIndexSpin->setObjectName("cspInterpIndexSpin");
        cspInterpIndexSpin->setMinimum(-10);
        cspInterpIndexSpin->setMaximum(0);
        cspInterpIndexSpin->setValue(-3);

        cspRuntimeFormLayout->setWidget(3, QFormLayout::FieldRole, cspInterpIndexSpin);


        leftLayout->addWidget(cspRuntimeGroupBox);

        advancedGroupBox = new QGroupBox(centralwidget);
        advancedGroupBox->setObjectName("advancedGroupBox");
        advancedFormLayout = new QFormLayout(advancedGroupBox);
        advancedFormLayout->setObjectName("advancedFormLayout");
        positionUnitLabel = new QLabel(advancedGroupBox);
        positionUnitLabel->setObjectName("positionUnitLabel");

        advancedFormLayout->setWidget(0, QFormLayout::LabelRole, positionUnitLabel);

        positionUnitLayout = new QHBoxLayout();
        positionUnitLayout->setObjectName("positionUnitLayout");
        degreeUnitRadio = new QRadioButton(advancedGroupBox);
        degreeUnitRadio->setObjectName("degreeUnitRadio");
        degreeUnitRadio->setChecked(true);

        positionUnitLayout->addWidget(degreeUnitRadio);

        turnUnitRadio = new QRadioButton(advancedGroupBox);
        turnUnitRadio->setObjectName("turnUnitRadio");

        positionUnitLayout->addWidget(turnUnitRadio);


        advancedFormLayout->setLayout(0, QFormLayout::FieldRole, positionUnitLayout);

        cspRxpdoPosAddrLabel = new QLabel(advancedGroupBox);
        cspRxpdoPosAddrLabel->setObjectName("cspRxpdoPosAddrLabel");

        advancedFormLayout->setWidget(1, QFormLayout::LabelRole, cspRxpdoPosAddrLabel);

        cspRxpdoPosAddrSpin = new QSpinBox(advancedGroupBox);
        cspRxpdoPosAddrSpin->setObjectName("cspRxpdoPosAddrSpin");
        cspRxpdoPosAddrSpin->setMaximum(65535);
        cspRxpdoPosAddrSpin->setValue(1);

        advancedFormLayout->setWidget(1, QFormLayout::FieldRole, cspRxpdoPosAddrSpin);

        cspTxpdoStatusAddrLabel = new QLabel(advancedGroupBox);
        cspTxpdoStatusAddrLabel->setObjectName("cspTxpdoStatusAddrLabel");

        advancedFormLayout->setWidget(2, QFormLayout::LabelRole, cspTxpdoStatusAddrLabel);

        cspTxpdoStatusAddrSpin = new QSpinBox(advancedGroupBox);
        cspTxpdoStatusAddrSpin->setObjectName("cspTxpdoStatusAddrSpin");
        cspTxpdoStatusAddrSpin->setMaximum(65535);

        advancedFormLayout->setWidget(2, QFormLayout::FieldRole, cspTxpdoStatusAddrSpin);

        cspTxpdoModeAddrLabel = new QLabel(advancedGroupBox);
        cspTxpdoModeAddrLabel->setObjectName("cspTxpdoModeAddrLabel");

        advancedFormLayout->setWidget(3, QFormLayout::LabelRole, cspTxpdoModeAddrLabel);

        cspTxpdoModeAddrSpin = new QSpinBox(advancedGroupBox);
        cspTxpdoModeAddrSpin->setObjectName("cspTxpdoModeAddrSpin");
        cspTxpdoModeAddrSpin->setMaximum(65535);
        cspTxpdoModeAddrSpin->setValue(3);

        advancedFormLayout->setWidget(3, QFormLayout::FieldRole, cspTxpdoModeAddrSpin);

        cspTxpdoPosAddrLabel = new QLabel(advancedGroupBox);
        cspTxpdoPosAddrLabel->setObjectName("cspTxpdoPosAddrLabel");

        advancedFormLayout->setWidget(4, QFormLayout::LabelRole, cspTxpdoPosAddrLabel);

        cspTxpdoPosAddrSpin = new QSpinBox(advancedGroupBox);
        cspTxpdoPosAddrSpin->setObjectName("cspTxpdoPosAddrSpin");
        cspTxpdoPosAddrSpin->setMaximum(65535);
        cspTxpdoPosAddrSpin->setValue(1);

        advancedFormLayout->setWidget(4, QFormLayout::FieldRole, cspTxpdoPosAddrSpin);


        leftLayout->addWidget(advancedGroupBox);


        topLayout->addLayout(leftLayout);

        rightLayout = new QVBoxLayout();
        rightLayout->setObjectName("rightLayout");
        buttonBox = new QGroupBox(centralwidget);
        buttonBox->setObjectName("buttonBox");
        buttonLayout = new QGridLayout(buttonBox);
        buttonLayout->setObjectName("buttonLayout");
        initCardButton = new QPushButton(buttonBox);
        initCardButton->setObjectName("initCardButton");

        buttonLayout->addWidget(initCardButton, 0, 0, 1, 1);

        closeCardButton = new QPushButton(buttonBox);
        closeCardButton->setObjectName("closeCardButton");

        buttonLayout->addWidget(closeCardButton, 0, 1, 1, 1);

        enableAxisButton = new QPushButton(buttonBox);
        enableAxisButton->setObjectName("enableAxisButton");

        buttonLayout->addWidget(enableAxisButton, 1, 0, 1, 1);

        disableAxisButton = new QPushButton(buttonBox);
        disableAxisButton->setObjectName("disableAxisButton");

        buttonLayout->addWidget(disableAxisButton, 1, 1, 1, 1);

        readPosButton = new QPushButton(buttonBox);
        readPosButton->setObjectName("readPosButton");

        buttonLayout->addWidget(readPosButton, 2, 0, 1, 1);

        stopButton = new QPushButton(buttonBox);
        stopButton->setObjectName("stopButton");

        buttonLayout->addWidget(stopButton, 2, 1, 1, 1);

        startButton = new QPushButton(buttonBox);
        startButton->setObjectName("startButton");

        buttonLayout->addWidget(startButton, 3, 0, 1, 2);


        rightLayout->addWidget(buttonBox);

        statusBox = new QGroupBox(centralwidget);
        statusBox->setObjectName("statusBox");
        statusLayout = new QFormLayout(statusBox);
        statusLayout->setObjectName("statusLayout");
        connectionTextLabel = new QLabel(statusBox);
        connectionTextLabel->setObjectName("connectionTextLabel");

        statusLayout->setWidget(0, QFormLayout::LabelRole, connectionTextLabel);

        connectionLabel = new QLabel(statusBox);
        connectionLabel->setObjectName("connectionLabel");

        statusLayout->setWidget(0, QFormLayout::FieldRole, connectionLabel);

        positionTextLabel = new QLabel(statusBox);
        positionTextLabel->setObjectName("positionTextLabel");

        statusLayout->setWidget(1, QFormLayout::LabelRole, positionTextLabel);

        positionLabel = new QLabel(statusBox);
        positionLabel->setObjectName("positionLabel");

        statusLayout->setWidget(1, QFormLayout::FieldRole, positionLabel);

        stateTextLabel = new QLabel(statusBox);
        stateTextLabel->setObjectName("stateTextLabel");

        statusLayout->setWidget(2, QFormLayout::LabelRole, stateTextLabel);

        stateLabel = new QLabel(statusBox);
        stateLabel->setObjectName("stateLabel");

        statusLayout->setWidget(2, QFormLayout::FieldRole, stateLabel);

        queueTextLabel = new QLabel(statusBox);
        queueTextLabel->setObjectName("queueTextLabel");

        statusLayout->setWidget(3, QFormLayout::LabelRole, queueTextLabel);

        queueLabel = new QLabel(statusBox);
        queueLabel->setObjectName("queueLabel");

        statusLayout->setWidget(3, QFormLayout::FieldRole, queueLabel);

        cycleTextLabel = new QLabel(statusBox);
        cycleTextLabel->setObjectName("cycleTextLabel");

        statusLayout->setWidget(4, QFormLayout::LabelRole, cycleTextLabel);

        cycleLabel = new QLabel(statusBox);
        cycleLabel->setObjectName("cycleLabel");

        statusLayout->setWidget(4, QFormLayout::FieldRole, cycleLabel);

        errorTextLabel = new QLabel(statusBox);
        errorTextLabel->setObjectName("errorTextLabel");

        statusLayout->setWidget(5, QFormLayout::LabelRole, errorTextLabel);

        errorLabel = new QLabel(statusBox);
        errorLabel->setObjectName("errorLabel");

        statusLayout->setWidget(5, QFormLayout::FieldRole, errorLabel);

        traceStatusTextLabel = new QLabel(statusBox);
        traceStatusTextLabel->setObjectName("traceStatusTextLabel");

        statusLayout->setWidget(6, QFormLayout::LabelRole, traceStatusTextLabel);

        traceStatusLabel = new QLabel(statusBox);
        traceStatusLabel->setObjectName("traceStatusLabel");

        statusLayout->setWidget(6, QFormLayout::FieldRole, traceStatusLabel);


        rightLayout->addWidget(statusBox);

        tipBox = new QGroupBox(centralwidget);
        tipBox->setObjectName("tipBox");
        tipLayout = new QVBoxLayout(tipBox);
        tipLayout->setObjectName("tipLayout");
        tipLabel = new QLabel(tipBox);
        tipLabel->setObjectName("tipLabel");
        tipLabel->setWordWrap(true);

        tipLayout->addWidget(tipLabel);


        rightLayout->addWidget(tipBox);


        topLayout->addLayout(rightLayout);


        rootLayout->addLayout(topLayout);

        errorPlotHost = new QWidget(centralwidget);
        errorPlotHost->setObjectName("errorPlotHost");

        rootLayout->addWidget(errorPlotHost);

        logEdit = new QPlainTextEdit(centralwidget);
        logEdit->setObjectName("logEdit");
        logEdit->setReadOnly(true);

        rootLayout->addWidget(logEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1180, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Motion Control", nullptr));
        motionGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Motion Config", nullptr));
        axisLabel->setText(QCoreApplication::translate("MainWindow", "Axis", nullptr));
        modeLabel->setText(QCoreApplication::translate("MainWindow", "Mode", nullptr));
        deltaAngleLabel->setText(QCoreApplication::translate("MainWindow", "Delta", nullptr));
        deltaAngleSpin->setSuffix(QCoreApplication::translate("MainWindow", " deg", nullptr));
        durationLabel->setText(QCoreApplication::translate("MainWindow", "Duration", nullptr));
        durationSpin->setSuffix(QCoreApplication::translate("MainWindow", " s", nullptr));
        systemPlanningPeriodLabel->setText(QCoreApplication::translate("MainWindow", "Planning Period", nullptr));
        systemPlanningPeriodMsSpin->setSuffix(QCoreApplication::translate("MainWindow", " ms", nullptr));
        minVelLabel->setText(QCoreApplication::translate("MainWindow", "Min Vel", nullptr));
        minVelSpin->setSuffix(QCoreApplication::translate("MainWindow", " deg/s", nullptr));
        maxVelLabel->setText(QCoreApplication::translate("MainWindow", "Max Vel", nullptr));
        maxVelSpin->setSuffix(QCoreApplication::translate("MainWindow", " deg/s", nullptr));
        trajectoryShapeLabel->setText(QCoreApplication::translate("MainWindow", "Trajectory", nullptr));
        sineAmplitudeLabel->setText(QCoreApplication::translate("MainWindow", "Sine Amp", nullptr));
        sineAmplitudeSpin->setSuffix(QCoreApplication::translate("MainWindow", " deg", nullptr));
        sineOmegaLabel->setText(QCoreApplication::translate("MainWindow", "Sine Omega", nullptr));
        sineOmegaSpin->setSuffix(QCoreApplication::translate("MainWindow", " rad/s", nullptr));
        reciprocatingLabel->setText(QCoreApplication::translate("MainWindow", "Reciprocate", nullptr));
        reciprocatingCheck->setText(QCoreApplication::translate("MainWindow", "Return to start after forward pass", nullptr));
        displayGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Display", nullptr));
        uiRefreshLabel->setText(QCoreApplication::translate("MainWindow", "UI Refresh", nullptr));
        uiRefreshMsSpin->setSuffix(QCoreApplication::translate("MainWindow", " ms", nullptr));
        cspRuntimeGroupBox->setTitle(QCoreApplication::translate("MainWindow", "CSP Runtime", nullptr));
        ecatPortLabel->setText(QCoreApplication::translate("MainWindow", "EtherCAT Port", nullptr));
        nodeLabel->setText(QCoreApplication::translate("MainWindow", "Node Index", nullptr));
        cspInterpPeriodMsLabel->setText(QCoreApplication::translate("MainWindow", "Interp Period (0x60C2:01)", nullptr));
        cspInterpPeriodMsSpin->setSuffix(QCoreApplication::translate("MainWindow", " ms", nullptr));
        cspInterpIndexLabel->setText(QCoreApplication::translate("MainWindow", "Time Base Index (0x60C2:02)", nullptr));
        advancedGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Advanced", nullptr));
        positionUnitLabel->setText(QCoreApplication::translate("MainWindow", "Position Unit", nullptr));
        degreeUnitRadio->setText(QCoreApplication::translate("MainWindow", "Degree", nullptr));
        turnUnitRadio->setText(QCoreApplication::translate("MainWindow", "Turn", nullptr));
        cspRxpdoPosAddrLabel->setText(QCoreApplication::translate("MainWindow", "Target Pos Addr (RxPDO)", nullptr));
        cspTxpdoStatusAddrLabel->setText(QCoreApplication::translate("MainWindow", "Status Addr (TxPDO 0x6041)", nullptr));
        cspTxpdoModeAddrLabel->setText(QCoreApplication::translate("MainWindow", "Mode Addr (TxPDO 0x6061)", nullptr));
        cspTxpdoPosAddrLabel->setText(QCoreApplication::translate("MainWindow", "Actual Pos Addr (TxPDO 0x6064)", nullptr));
        buttonBox->setTitle(QCoreApplication::translate("MainWindow", "Control", nullptr));
        initCardButton->setText(QCoreApplication::translate("MainWindow", "Init Board", nullptr));
        closeCardButton->setText(QCoreApplication::translate("MainWindow", "Close Board", nullptr));
        enableAxisButton->setText(QCoreApplication::translate("MainWindow", "Enable Axis", nullptr));
        disableAxisButton->setText(QCoreApplication::translate("MainWindow", "Disable Axis", nullptr));
        readPosButton->setText(QCoreApplication::translate("MainWindow", "Read Pos", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop Motion", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start Motion", nullptr));
        statusBox->setTitle(QCoreApplication::translate("MainWindow", "Status", nullptr));
        connectionTextLabel->setText(QCoreApplication::translate("MainWindow", "Board", nullptr));
        connectionLabel->setText(QCoreApplication::translate("MainWindow", "Not Init", nullptr));
        positionTextLabel->setText(QCoreApplication::translate("MainWindow", "Position", nullptr));
        positionLabel->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        stateTextLabel->setText(QCoreApplication::translate("MainWindow", "State", nullptr));
        stateLabel->setText(QCoreApplication::translate("MainWindow", "Idle", nullptr));
        queueTextLabel->setText(QCoreApplication::translate("MainWindow", "Queue Depth", nullptr));
        queueLabel->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        cycleTextLabel->setText(QCoreApplication::translate("MainWindow", "Sent/Queue", nullptr));
        cycleLabel->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        errorTextLabel->setText(QCoreApplication::translate("MainWindow", "Error", nullptr));
        errorLabel->setText(QCoreApplication::translate("MainWindow", "Current error: -- deg", nullptr));
        traceStatusTextLabel->setText(QCoreApplication::translate("MainWindow", "Trace", nullptr));
        traceStatusLabel->setText(QCoreApplication::translate("MainWindow", "Inactive", nullptr));
        tipBox->setTitle(QCoreApplication::translate("MainWindow", "Notes", nullptr));
        tipLabel->setText(QCoreApplication::translate("MainWindow", "Tips", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
