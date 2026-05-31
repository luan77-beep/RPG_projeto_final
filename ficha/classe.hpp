#ifndef CLASSE_HPP
#define CLASSE_HPP

#include <string>

class IClasse{
public:
	virtual std::string getNome() = 0;
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
	const std::string nome = "Mago";
	inline static double vida = 74.0, bonusDano = 0.1, bonusResistencia = 0.01;
public:
	Mago() {}
	std::string getNome() override {return nome;}
	double getVida() override {return vida;}
	double getBonusDano() override {return bonusDano;}
	double getBonusResistencia() override {return bonusResistencia;}
	void setVida(double novaVida) override {vida = novaVida;}
	void setBonusDano(double novoBonusDano) override {bonusDano = novoBonusDano;}
	void setBonusResistencia(double novoBonusResistencia) override {bonusResistencia = novoBonusResistencia;}
};

class Guerreiro: public IClasse{
private:
	const std::string nome = "Guerreiro";
	inline static double vida = 80.0, bonusDano = 0.05, bonusResistencia = 0.04;

public:
	Guerreiro() {}
	std::string getNome() {return nome;}
	double getVida() override {return vida;}
	double getBonusDano() override {return bonusDano;}
	double getBonusResistencia() override {return bonusResistencia;}
	void setVida(double novaVida) override {vida = novaVida;}
	void setBonusDano(double novoBonusDano) override {bonusDano = novoBonusDano;}
	void setBonusResistencia(double novoBonusResistencia) override {bonusResistencia = novoBonusResistencia;}

};

class Arqueiro: public IClasse{
private:
	const std::string nome = "Arqueiro";
	inline static double vida = 77.0, bonusDano = 0.075, bonusResistencia = 0.025;

public:
	Arqueiro() {}
	std::string getNome() {return nome;}
	double getVida() override {return vida;}
	double getBonusDano() override {return bonusDano;}
	double getBonusResistencia() override {return bonusResistencia;}
	void setVida(double novaVida) override {vida = novaVida;}
	void setBonusDano(double novoBonusDano) override {bonusDano = novoBonusDano;}
	void setBonusResistencia(double novoBonusResistencia) override {bonusResistencia = novoBonusResistencia;}
};

#endif