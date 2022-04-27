#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H

#include <QPushButton>

class GameButton : public QPushButton
{
    Q_OBJECT

public:
    explicit GameButton(QPushButton *parent = nullptr);
    void setPosition(const int row, const int col);

private slots:
    void handleClicked();

signals:
    void buttonToggled(int row, int col);

private:
    int m_row;
    int m_col;
};

#endif // BUTTON_H
