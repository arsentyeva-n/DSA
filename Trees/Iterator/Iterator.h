#pragma once
template <class T> class Iterator {
protected:
    /// флажок, показывающий, достиг ли итератор конца списка.
    /// должен поддерживатьс€ производными классами
    int iterationComplete;
public:
    /// конструктор
    Iterator(void);

    // об€зательные методы итератора:
    virtual void Next(void) = 0;
    virtual void Reset(void) = 0;
    /// методы дл€ выборки/модификации данных
    virtual “& Data(void) = 0;
    /// проверка конца списка
    virtual int EndOfList(void) const;
};
