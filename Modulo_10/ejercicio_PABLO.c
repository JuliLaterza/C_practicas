void mostrar() {
	FILE *cfptr;
	int legajo;
	float sueldo;
	int edad;
	int materias_cursadas;
	int materias_aprobadas;
	int materias_reprobadas;

	if ((cfptr=fopen("estudiantes.dat","r"))==NULL) {
		printf("\n No Se puede Abrir!!!.");
	} else {
		while(!feof(cfptr)) {
			fscanf(cfptr,"%d|%d|%d|%d|%d\n",&legajo, &edad, &materias_cursadas, &materias_aprobadas, &materias_reprobadas);
			if(materias_reprobadas == 0 && edad > 35) {
				printf("Legajo: %d   \nEdad: %d   \nCursadas: %d   \nAprobadas: %d   \nReprobadas: %d\n",legajo,edad,materias_cursadas,materias_aprobadas,materias_reprobadas);
			}
		}
	}
	fclose(cfptr);
}