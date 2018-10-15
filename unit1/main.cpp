#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

void c1_1()
{
    QLabel *label= new QLabel("<H2><i>Hello </i>"
                              "<font color=red> Qt!</font></H2>");
    label->show();
}

void c1_2()
{
    QPushButton *button = new QPushButton("Quit");
    QObject::connect(button,SIGNAL(clicked()), qApp, SLOT(quit()));
    button->show();
}

void c1_3()
{
    QWidget *window = new QWidget;
    window->setWindowTitle(u8"请输入您的年龄");
    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(10,130);
    slider->setRange(10,130);

    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
    //QObject::connect(spinBox, &QSpinBox::valueChanged, slider, &QSlider::setValue);
    QObject::connect(spinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
                     slider, &QSlider::setValue);


    spinBox->setValue(31);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window->setLayout(layout);
    //window->setFixedSize(800, 600);
    window->setMinimumSize(370, 150);
    window->setMaximumSize(370, 150);


    window->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //c1_1();
    //c1_2();
    c1_3();
    //c1_4();
    return a.exec();
}
