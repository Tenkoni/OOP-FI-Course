

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

class IChannel
{
public:
    virtual void ChannelUp () = 0;
    virtual void ChannelDown () = 0;
};
/*
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
*/
class MiRadio : public IDevice, public IVolume, public IChannel
{
private:
    double channel {88.1};
    int volume {0};
    bool state {false};
public:
    MiRadio () = default;
    MiRadio (double _channel, int _volume, bool _state);
    virtual ~MiRadio () = default;
    virtual void SwitchOn () override;
	virtual void SwitchOff () override;

	virtual void VolumeUp () override;
	virtual void VolumeDown () override;
	
	virtual void ChannelUp () override;
	virtual void ChannelDown () override;
	void Print ();	
};

MiRadio::MiRadio (double _channel, int _volume, bool _state)
                : channel {_channel}, volume {_volume}, state {_state}
{
//nada
}

void MiRadio::SwitchOn ()
{
	if (this->state == false) {
		this->state = true;
	}
}

void MiRadio::SwitchOff ()
{
	if (this->state == true) {
		this->state = false;
		this->volume = 0;
		this->channel = 88.1;
		
	}
}

void MiRadio::VolumeUp ()
{
	if (this->state == true) {
		++this->volume;
		if (this->volume > 9) {
			this->volume = 9;
		}
	}
}

void MiRadio::VolumeDown ()
{
	if (this->state == true) {
		--this->volume;
		if (this->volume < 0 ) {
			this->volume = 0;
		}
	}
}

void MiRadio::ChannelUp ()
{
	if (this->state == true) {
		this->channel += 0.2;
		if (this->channel > 107.9 ) {
			this->channel = 88.1;
		}
	}
}

void MiRadio::ChannelDown()
{
	if (this->state == true) {
		this->channel -= 0.2;
		if (this->channel < 88.1 ) {
			this->channel = 107.9;
		}
	}
}

void MiRadio::Print ()
{
	std::cout << "Estado: ";
	if (this->state == false) {
		std::cout << "Apagado\n";
	}
	else {
		std::cout << "Encendido\n";
	}

	std::cout << "Volumen: " << this->volume << std::endl;
    std::cout << "Estacion: " << this->channel << std::endl;
}
/*-----------------------------------------------------------------------------
 *              Menú para probar los diferentes comportamientos
 *-----------------------------------------------------------------------------*/
int menu ()
{

	while (1) {
		printf ("\n");
		printf ("(1) APAGAR EL RADIO\n");
		printf ("(2) ENCENDER EL RADIO\n");
		printf ("(3) SUBIR EL VOLUMEN UNA UNIDAD\n");
		printf ("(4) BAJAR EL VOLUMEN UNA UNIDAD\n");
		printf ("(5) SUBIR UNA ESTACION\n");
		printf ("(6) BAJAR UNA ESTACION\n");
		printf ("(0) TERMINAR\n");
		printf ("> ");

		int op = 0;
		scanf ("%d", &op);

		if (0 <= op && op <= 6) {
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
	MiRadio radio;

	while (1)
	{
		switch (menu ()) {
			case 0:
				return 0;

			case 1:
				radio.SwitchOff ();
				radio.Print ();
				break;

			case 2:
				radio.SwitchOn ();
				radio.Print ();
				break;

			case 3:
				radio.VolumeUp ();
				radio.Print ();
				break;

			case 4:
				radio.VolumeDown ();
				radio.Print ();
				break;
				
			case 5:
				radio.ChannelUp ();
				radio.Print ();
				break;

			case 6:
				radio.ChannelDown ();
				radio.Print ();
				break;

			default:
				break;
		}
	}

}
