void SystemInit(){}
#define SYSCTL_RCGCGPIO_R			(*((volatile unsigned long *)0x400FE608)) //Clock Signal variable.
#define GPIO_PORTF_DATA_R			(*((volatile unsigned long *)0x400253FC)) //Data variable to display as output.
#define GPIO_PORTF_DIR_R			(*((volatile unsigned long *)0x40025400)) //Direction variable to specify wether pin act as input or output.
#define GPIO_PORTF_DEN_R			(*((volatile unsigned long *)0x4002551C)) //Digital enabler to enable a specific pin of a specific port.

#define GPIO_PORTF_CLK_EN			0x20                                      //Provides clock to PORT F and enables it.
#define GPIO_PORTF_PIN_EN			0x08					  //Provide clock to the specific pin of the PORT F.
#define DELAY					200000					  //Decides the frequency of blinking LED.

int __main(void)
{ 
	int a=0;
	volatile unsigned long ulLoop;   						 
	SYSCTL_RCGCGPIO_R |= GPIO_PORTF_CLK_EN;						  
	ulLoop=SYSCTL_RCGCGPIO_R;
	while(1)
	{
		GPIO_PORTF_DIR_R |= a;
		GPIO_PORTF_DEN_R |= a;
		GPIO_PORTF_DATA_R |= a; 
		for(ulLoop = 0; ulLoop < DELAY; ulLoop++);
		GPIO_PORTF_DATA_R &= a; 
		for(ulLoop = 0; ulLoop<DELAY; ulLoop++);
		a++;
		a=a%15;
	}
}