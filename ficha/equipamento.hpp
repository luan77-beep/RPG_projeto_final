#ifndef EQUIPAMENTO_HPP
#define EQUIPAMENTO_HPP

class IEquipamento{
public:
    virtual double getDano() = 0;
    virtual void setDano(double novoDano) = 0;
};

class Espada : public IEquipamento{
private:
    inline static double dano = 12.8;
public:
    double getDano() override {return dano;}
    void setDano(double novoDano) override {dano = novoDano;}
};

class Adagas : public IEquipamento{
private:
    inline static double dano = 10.5;
public:
    double getDano() override {return dano;}
    void setDano(double novoDano) override {dano = novoDano;}
};

class Lanca: public IEquipamento {
private:
     inline static double dano = 11.6;
public:
    double getDano() override {return dano;}
    void setDano(double novoDano) override {dano = novoDano;}
};

class Arco: public IEquipamento{
private:
    inline static double dano = 13.4;
public:
    double getDano() override {return dano;}
    void setDano(double novoDano) {dano = novoDano;}
};
#endif