#include <fcntl.h> // Para usar open
#include <stdio.h> // Para usar printf
#include <stdlib.h> // Para usar malloc y free
#include "get_next_line.h"// Incluye el header con el prototipo de get_next_line

int main(int argc, char **argv)
{
    int i = 0;
    // Verifica que se le haya pasado el nombre del archivo
    if (argc != 2) {
        printf("Uso: %s <nombre_del_archivo>\n", argv[0]);
        return (1);
    }

    // Abre el archivo en modo de solo lectura
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        return (1);
    }

    char *line;
    // Llama a get_next_line repetidamente en un bucle
    while ((line = get_next_line(fd)) != NULL && i < 10) {
        printf("---6-%s", line); // Imprime la línea leída
        free(line); // Libera la memoria asignada para la línea
        i++;
    }

    // Cierra el archivo
    close(fd);
    return (0);
}
