#include <QApplication>
#include <QPaintEvent>
#include <QVBoxLayout>
#include <QPainter>
#include <QPixmap>
#include <QSlider>
#include <QPushButton>

class Circle : public QWidget
{
    Q_OBJECT
private:
    QPixmap redCircle;
    QPixmap yellowCircle;
    QPixmap greenCircle;
    QPixmap currentCircle;
public:
    Circle() = default;
    Circle(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize minimumSizeHint() const override;
public slots:
    void setRed();
    void setYellow();
    void setGreen();
};

Circle::Circle(QWidget *parent)
{
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    redCircle = QPixmap("..\\img\\red_circle.png");
    yellowCircle = QPixmap("..\\img\\yellow_circle.png");
    greenCircle = QPixmap("""..\\img\\green_circle.png");
    currentCircle = greenCircle;
    setGeometry(currentCircle.rect());
}

void Circle::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), currentCircle);
}

QSize Circle::minimumSizeHint() const
{
    return QSize(180, 180);
}

void Circle::setRed()
{
    currentCircle = redCircle;
    update();
}

void Circle::setYellow()
{
    currentCircle = yellowCircle;
    update();
}

void Circle::setGreen()
{
    currentCircle = greenCircle;
    update();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *window = new QWidget;
    window->setFixedSize(200, 250);
    window->move(800, 300);
    auto *circle = new Circle(window);
    auto *slider = new QSlider(Qt::Horizontal, window);
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setTickPosition(QSlider::TicksBothSides);
    auto *layout = new QVBoxLayout(window);
    layout->addWidget(circle);
    layout->addWidget(slider);

    auto changeColor = [&slider, &circle]()
    {
        int value = slider->value();
        if (value >= 0 && value <= 33)
            circle->setGreen();
        else if (value <= 66)
            circle->setYellow();
        else
            circle->setRed();
    };

    QObject::connect(slider, &QSlider::valueChanged, changeColor);
    window->show();
    return QApplication::exec();
}

#include "main.moc"