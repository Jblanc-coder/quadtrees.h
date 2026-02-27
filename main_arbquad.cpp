#include <iostream>
#include <vector>
#include "arbquad.h"

using namespace std;

void imprimirSeparador(string titulo) {
	
    cout << "\n========================================" << endl;
    cout << " TEST: " << titulo << endl;
    cout << "========================================" << endl;
    
}

int main() {
	
    TArbQuad arbTool; 

    // 1. Probar hojas básicas
    imprimirSeparador("Hojas basicas");
    TArbQuad b = arbTool.blanco();
    TArbQuad n = arbTool.negro();
    
    cout << "Arbol Blanco:"; b.escribe();
    cout << "Arbol Negro:"; n.escribe();
    
    cout << "Es blanco? " << (b.esBlanco() ? "SI" : "NO") << endl;
    cout << "Es negro? " << (n.esNegro() ? "SI" : "NO") << endl;

    // 2. Probar Plantar con mezcla (Crea un nodo interno 'I')
    imprimirSeparador("Plantar (Mezclado)");
    TArbQuad mixto = arbTool.plantar(b, n, b, n);
    cout << "Arbol mixto (B, N, B, N):";
    mixto.escribe();

    // 3. Probar Compresion Automática
    imprimirSeparador("Compresion automatica");
    TArbQuad autoB = arbTool.plantar(b, b, b, b);
    cout << "Arbol plantado con 4 blancos (deberia ser solo una hoja B):";
    autoB.escribe();

    // 4. Probar Negativo
    imprimirSeparador("Operacion Negativo");
    TArbQuad negMixto = mixto.negativo();
    cout << "Negativo del arbol mixto (deberia ser N, B, N, B):";
    negMixto.escribe();

    // 5. Probar Hijo
    imprimirSeparador("Acceso a Hijos");
    TArbQuad h2 = mixto.hijo(2);
    cout << "Hijo 2 del arbol mixto (deberia ser N):";
    h2.escribe();

    // 6. Probar Matriz a Arbol (Matriz 4x4)
    imprimirSeparador("Matriz a Arbol (4x4)");
    vector<vector<bool>> matriz = {
        {true,  true,  false, false},
        {true,  true,  false, false},
        {false, false, false, false},
        {false, false, false, false}
    };

    TArbQuad arbMatriz = arbTool.matriztoArb(matriz);
    cout << "Resultado de convertir matriz 4x4:";
    arbMatriz.escribe();
    cout << "\nNota: Si la compresion funciona, el arbol deberia mostrar" << endl;
    cout << "que el cuadrante superior izquierdo es Blanco y el resto Negro." << endl;

    return 0;
}