#pragma once
template <class T> class Iterator {
protected:
    /// ������, ������������, ������ �� �������� ����� ������.
    /// ������ �������������� ������������ ��������
    int iterationComplete;
public:
    /// �����������
    Iterator(void);

    // ������������ ������ ���������:
    virtual void Next(void) = 0;
    virtual void Reset(void) = 0;
    /// ������ ��� �������/����������� ������
    virtual �& Data(void) = 0;
    /// �������� ����� ������
    virtual int EndOfList(void) const;
};
