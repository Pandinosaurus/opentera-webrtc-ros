#include "ConfigDialog.h"
#include "MainWindow.h"

#include "ui_ConfigDialog.h"

ConfigDialog::ConfigDialog(MainWindow* parent) : m_ui(new Ui::ConfigDialog())
{
    m_ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowTitleHint);

    // Sliders
    m_ui->micVolumeSlider->setValue(100);
    connect(m_ui->micVolumeSlider, &QSlider::valueChanged, parent, &MainWindow::onMicVolumeSliderValueChanged);
    m_ui->volumeSlider->setValue(100);
    connect(m_ui->volumeSlider, &QSlider::valueChanged, parent, &MainWindow::onVolumeSliderValueChanged);
}

ConfigDialog::~ConfigDialog() {}


int ConfigDialog::getMicVolumeSliderValue()
{
    return m_ui->micVolumeSlider->value();
}

void ConfigDialog::setMicVolumeSliderValue(int value)
{
    m_ui->micVolumeSlider->setValue(value);
}

int ConfigDialog::getVolumeSliderValue()
{
    return m_ui->volumeSlider->value();
}

void ConfigDialog::setVolumeSliderValue(int value)
{
    m_ui->volumeSlider->setValue(value);
}
