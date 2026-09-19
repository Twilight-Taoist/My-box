#include <stdio.h>

int main()
{
	/*初始化*/
	int plice=0;
	int bill=0; 
	/*读取数据*/
	printf("请输入金额：");
	scanf("%d",&plice);
	printf("请输入票面：");
	scanf("%d",&bill);
	/*计算并判断*/
	int pay=bill-plice;
	if (pay>=0) {printf("应找您%d元。",pay);
	}else{printf("您的钱不够。");
	}
	
	return 0;
}
