__gloval__ void mykernel(void){}

int main(void)
{
	mykernel<<<1,1>>>();
	printf("Hello World! \n");
	return 0;
}
