/********
* Fichier: monInterface.h
* Auteurs: C.-A. Brunet
* Date: 21 décembre 2021 (création)
* Description: La classe MonInterface teste l'interface usager GraphicusGUI.
*
* Copyright 2022 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include "graphicusGUI.h"

class MonInterface : public GraphicusGUI
{
public:
	MonInterface(const char *theName = nullptr);
	virtual void reinitialiserCanevas();
};

#endif // MONINTERFACE_H