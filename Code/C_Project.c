/*
 ============================================================================
 Name        : C_Project.c
 Author      : Hisham Elsayed
 Version     :
 Copyright   : Your copyright notice
 Description : C Programming Project
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


char choice;
int temp = 35;
int speed;
int engine_t = 90;
short state_engine;
short ac;
short controller;

void sensors_set_menu();
void traffic_color();
void room_temp();
void engine_temp();
void display();



void menu ()
{
	printf("Do you want to:\n");
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	scanf(" %c",&choice);

	if ( choice == 'c')
	{
		printf("Quitting program");
		exit(1);
	}
	else if ( choice == 'b')
	{
		state_engine=0;
		ac=0;
		controller=0;
		printf("Turning off vehicle...\n");

		menu();
	}
	else if ( choice == 'a')
	{
		state_engine = 1;      // Engine ON //
		printf("Turning on vehicle...\n");
		printf("\n");
		sensors_set_menu();
		while (choice =='b' || 'c' || 'd')
		{
			sensors_set_menu();         // Return back to this menu again //
			printf("\n");
		}

	}
	else
		printf("Invalid input");

}

void sensors_set_menu()
{

	printf("Do you want to:\n");
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");
	printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
	scanf(" %c",&choice);
	if (choice == 'b')
	{
		printf("Please insert the first word of the color:\n");
		traffic_color();
		printf("\n");
	}
	else if (choice == 'c')
	{
		room_temp();
		printf("\n");
	}
	else if (choice == 'd')
	{
		engine_temp();
		printf("\n");
	}
	else if (choice == 'a')
	{
        state_engine=0;
        ac=0;
        controller=0;
		printf("Turning off engine..\n");

	    menu();


	}

	else
	{
		printf("Invalid input\n");
	}

}

void traffic_color()
{

	scanf(" %c",&choice);
	if (choice == 'G' || choice == 'g' )
	{
		speed = 100;
		printf("Speed = %d km/hr\n",speed);
	}
	else if (choice == 'O' || choice == 'o' )
	{
		speed = 30;
		ac=1;
		controller = 1;
		temp = (float)temp * (5.0/4.0) + 1;
		engine_t = (float)engine_t * (5.0/4.0) + 1;
		printf("Speed = %d km/hr\n",speed);
	}
	else if (choice == 'R' || choice == 'r')
	{
		speed = 0;
		printf("Speed = %d km/hr\n",speed);
	}
	else
	{
		printf("Invalid input\n");
	}
	display();
}

void room_temp()
{

	printf("Insert Room Temperature value:\n");
	scanf(" %d",&temp);
	if (temp < 10)
	{
        ac=1;
		printf("Turning AC ON..\n");
		temp = 20;
		printf("Temperature is set to %d C\n",temp);
	}
	else if (temp > 30)
	{
        ac = 1;

		printf("Turning AC ON..\n");
		temp = 20;
		printf("Temperature is set to %d C\n",temp);
	}

	else if (speed == 30)
	{
            ac = 1;
			printf("Turning AC back ON\n");
			temp = (float)temp * (5.0/4.0) + 1;
			printf ("Room Temperature now is set to: %d C\n",temp);
	}
	else
	{
            ac = 0;
		    printf("Turning AC OFF\n");
	}
	display();
}



void engine_temp()
{
	controller =1 ;
	printf("Please insert Sensor Temperature value:\n");
	scanf(" %d",&engine_t);
	if ( engine_t < 100)
	{

		printf("Turning Engine Temperature Controller ON..\n");
		engine_t=125;
		printf("Temperature is set to %d C\n",engine_t);
	}
	else if (engine_t > 150)
	{

		printf("Turning Engine Temperature Controller ON..\n");
		engine_t=125;
		printf("Temperature is set to %d C\n",engine_t);
	}
	else if (speed == 30)
	{

		printf("Turning Engine Temperature Controller back ON\n");
		engine_t = (float)engine_t * (5.0/4.0) + 1;

		printf ("Engine Temperature now is set to: %d C\n",engine_t);
	}
	else
	{
        controller = 0;
		printf("Turning Engine Temperature Controller OFF..\n");
	}
	display();
}

void display()
{


    if( state_engine == 0)
    {
    	printf("Engine state:OFF\n");
    }
    else
    {
    	printf("Engine state:ON\n");
    }

    if ( ac == 0)
    {
    	printf("AC:OFF\n");
    }
    else
    {
    	printf("AC:ON\n");
    }
    ;
    if (controller == 0)
    {
    	printf("Engine Temperature Controller State:OFF\n");
    }
    else
    {
    	printf("Engine Temperature Controller State:ON\n");
    }
    printf("Vehicle speed is:%d km/hr\n",speed);
    printf("Room Temperature is:%d C\n",temp);
    printf("Engine Temperature is:%d C\n",engine_t);
}



int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	menu();




}
