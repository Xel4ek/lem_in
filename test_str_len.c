#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int main(){
    char *str = "1280918231829031828uoijfcdlqn3lr1vhnhbaazfnlfenflknqlhli4qhrn2vboiqnhvujrm;d32ri;2rcivprjc;	XJX;JNJ;VQIJ;NIJ;QjQEVR;jQCJICRJ;QR;Ijcvr;JCR;QJIR;	OCN;RQIJ";

    printf("strlen: %ld\n", strlen(str));
    printf("strlen: %9ld\n", ft_strlen(str));
	ft_printf("strlen: %9ld\n", ft_strlen(str));
    ft_printf("test\n");

    return 0;
}