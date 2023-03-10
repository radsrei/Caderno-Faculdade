void inclui( int total, struct pessoa cadastro);
float altura_media(int total, struct pessoa cadastro);


inclui( int total, struct pessoa cadastro){
	int novo;
	if(total<50){
		novo=total+1;
		scanf("%c",&struct pessoa[novo].nome);
		scanf("%f",&struct pessoa[novo].altura);
	}
}




altura_media(int total, struct pessoa cadastro){
	int i;
	float soma,media;
	for(i<0;i<total;i++){
		soma+=pessoa[i].altura;
	}
	media=soma/total;
	
	return media;
}
