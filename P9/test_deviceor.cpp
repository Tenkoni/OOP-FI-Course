

#include <iostream>

class IDevice
{
public:
	virtual void SwitchOn () = 0;
	virtual void SwitchOff () = 0;
};

class IVolume
{
public:
	virtual void VolumeUp () = 0;
	virtual void VolumeDown () = 0;
};

class CellPhone : public IDevice, public IVolume
{
public:
	virtual void SwitchOn () override;
	virtual void SwitchOff () override;

	virtual void VolumeUp () override;
	virtual void VolumeDown () override;

	void Print ();

private:
	int volume {0};
	bool state {false};
};

void CellPhone::SwitchOn ()
{
	if (this->state == false) {
		this->state = true;
	}
}

void CellPhone::SwitchOff ()
{
	if (this->state == true) {
		this->state = false;
		this->volume = 0;
	}
}

void CellPhone::VolumeUp ()
{
	if (this->state == true) {
		++this->volume;
		if (this->volume > 9) {
			this->volume = 9;
		}
	}
}

void CellPhone::VolumeDown ()
{
	if (this->state == true) {
		--this->volume;
		if (this->volume < 0 ) {
			this->volume = 0;
		}
	}
}

void CellPhone::Print ()
{
	std::cout << "Estado: ";
	if (this->state == false) {
		std::cout << "Apagado\n";
	}
	else {
		std::cout << "Encendido\n";
	}

	std::cout << "Volumen: " << this->volume << std::endl;
}

/*-----------------------------------------------------------------------------
 *              Menú para probar los diferentes comportamientos
 *-----------------------------------------------------------------------------*/
int menu ()
{

	while (1) {
		printf ("\n");
		printf ("(1) APAGAR EL CELULAR\n");
		printf ("(2) ENCENDER EL CELULAR\n");
		printf ("(3) SUBIR EL VOLUMEN UNA UNIDAD\n");
		printf ("(4) BAJAR EL VOLUMEN UNA UNIDAD\n");
		printf ("(0) TERMINAR\n");
		printf ("> ");

		int op = 0;
		scanf ("%d", &op);

		if (0 <= op && op <= 4) {
			printf ("\n");
			return op;
		}
		else {
			printf ("OPCIÓN NO VÁLIDA\n");
		}
	}
}




int main(void)
{
	CellPhone htc;

	while (1)
	{
		switch (menu ()) {
			case 0:
				return 0;

			case 1:
				htc.SwitchOff ();
				htc.Print ();
				break;

			case 2:
				htc.SwitchOn ();
				htc.Print ();
				break;

			case 3:
				htc.VolumeUp ();
				htc.Print ();
				break;

			case 4:
				htc.VolumeDown ();
				htc.Print ();
				break;

			default:
				break;
		}
	}

}
