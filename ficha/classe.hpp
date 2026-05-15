#ifndef CLASSE_HPP
#define CLASSE_HPP

#include <string>

class IClasse{
public:
	virtual double getVida() = 0;
	virtual double getBonusDano()= 0;
	virtual double getBonusResistencia() = 0;
	virtual void setVida(double novaVida) = 0;
	virtual void setBonusDano(double novoBonusDano) = 0;
	virtual void setBonusResistencia(double novoBonusResistencia) = 0;
	virtual ~IClasse() = default;
};

class Mago: public IClasse{
private:
	inline static double vida = 36.0, bonusDano = 0.1, bonusResistencia = 0.01;
public:
	double getVida() override {return vida;}
	double getBonusDano() override {return bonusDano;}
	double getBonusResistencia() override {return bonusResistencia;}
	void setVida(double novaVida) override {vida = novaVida;}
	void setBonusDano(double novoBonusDano) override {bonusDano = novoBonusDano;}
	void setBonusResistencia(double novoBonusResistencia) override {bonusResistencia = novoBonusResistencia;}
};

class Guerreiro: public IClasse{
private:
	inline static double vida = 41.0, bonusDano = 0.05, bonusResistencia = 0.04;

public:
	double getVida() override {return vida;}
	double getBonusDano() override {return bonusDano;}
	double getBonusResistencia() override {return bonusResistencia;}
	void setVida(double novaVida) override {vida = novaVida;}
	void setBonusDano(double novoBonusDano) override {bonusDano = novoBonusDano;}
	void setBonusResistencia(double novoBonusResistencia) override {bonusResistencia = novoBonusResistencia;}

};

class Arqueiro: public IClasse{
private:
	inline static double vida = 39.0, bonusDano = 0.075, bonusResistencia = 0.025;

public: 
	double getVida() override {return vida;}
	double getBonusDano() override {return bonusDano;}
	double getBonusResistencia() override {return bonusResistencia;}
	void setVida(double novaVida) override {vida = novaVida;}
	void setBonusDano(double novoBonusDano) override {bonusDano = novoBonusDano;}
	void setBonusResistencia(double novoBonusResistencia) override {bonusResistencia = novoBonusResistencia;}
};

#endif