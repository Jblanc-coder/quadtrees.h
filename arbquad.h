#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*

 especificación ARBQUAD

 usa BOOLEANOS, NAT

 tipos arbquad

 operaciones
 
    blanco   :                                      -->  arbquad {constructora}
    negro    :                                      -->  arbquad {constructora}
    plantar  : arbquad arbquad arbquad arbquad      -->  arbquad {constructora}
    blanco?  : arbquad                              -->  bool
    negro?   : arbquad                              -->  bool
    hijo     : arbquad nat                          -/-> arbquad
    negativo : arbquad                              -->  arbquad
    
 variables
 
    a1, a2, a3, a4 : arbquad
    n              : nat
    
 ecuaciones
 
    plantar(blanco,blanco,blanco,blanco) = blanco 
	plantar(negro,negro,negro,negro)     = negro

    blanco?(blanco)               = true 
	blanco?(negro)                = false 
	blanco?(plantar(a1,a2,a3,a4)) = true  <== blanco?(a1) ^ blanco?(a2) ^ blanco?(a3) ^ blanco?(a4)
	blanco?(plantar(a1,a2,a3,a4)) = false <== ¬blanco?(a1) \/ ¬blanco?(a2) \/ ¬blanco?(a3) \/ ¬blanco?(a4) 
	
	negro?(blanco)               = true 
	negro?(negro)                = false 
	negro?(plantar(a1,a2,a3,a4)) = true  <== negro?(a1) ^ negro?(a2) ^ negro?(a3) ^ negro?(a4)
	negro?(plantar(a1,a2,a3,a4)) = false <== ¬negro?(a1) \/ ¬negro?(a2) \/ ¬negro?(a3) \/ ¬negro?(a4) 
	
	hijo(a1,n)                   = error <== n<1 \/ n>4
	hijo(blanco,n)               = blanco
	hijo(negro,n)                = negro
	hijo(plantar(a1,a2,a3,a4),n) = an
	
	negativo(blanco)               = negro
	negativo(negro)                = blanco
	negativo(plantar(a1,a2,a3,a4)) = plantar(negativo(a1),negativo(a2),negativo(a3),negativo(a4))
	
 fespecificacion
 
 */
 
 class TNodoQuad {
 	
    public:
    	
    	char& color();
    	TNodoQuad* a1();
    	TNodoQuad* a2();
    	TNodoQuad* a3();
    	TNodoQuad* a4();
    	
    private:
    	
    	char _color;
    	
    	TNodoQuad *_a1, *_a2, *_a3, *_a4;
    	
    	TNodoQuad( char _color, TNodoQuad*, TNodoQuad*, TNodoQuad*, TNodoQuad*);
    	
    friend class TArbQuad;
    
};

class TArbQuad {

    public:
    	
    	//Constructoras
    	TArbQuad();
    	TArbQuad( char color(), TArbQuad&, TArbQuad&, TArbQuad&, TArbQuad&);
    	
    	TArbQuad blanco();
    	// Pre: true
    	// Post: devuelve un árbol en forma de hoja blanca
    	// O(1)
    	
    	TArbQuad negro();
    	// Pre: true
    	// Post: devuelve un árbol en forma de hoja negra
    	// O(1)
    	
    	bool esVacio();
    	// Pre: true
    	// Post: devuelve si un árbol es vacío
    	// O(1)
    	
    	TArbQuad plantar( const TArbQuad&, const TArbQuad&, const TArbQuad&, const TArbQuad&);
    	// Pre: true
    	// Post: devuelve un árbol a partir de cuatro árboles
    	// O(1)
    	
    	bool esBlanco();
    	// Pre: true
    	// Post: devuelve si un árbol es blanco
    	// O(1)
    	
    	bool esNegro();
    	// Pre: true
    	// Post: devuelve si un árbol es negro
    	// O(1)
    	
    	TArbQuad hijo( int n);
    	// Pre: árbol no vacío y 1 <= n <= 4
    	// Post: devuelve el hijo del nodo n
    	// O(1)
    	
    	TArbQuad negativo();
    	// Pre: true
    	// Post: devuelve un árbol con colores inversos
    	// O(n)
    	
    	TArbQuad matriztoArb(vector<vector<bool>> matrix);
    	// Pre: matriz 2^n x 2^n
    	// Post: devuelve un árbol a partir de una matriz
    	// O(n^2)
    	
    	vector<vector<bool>> getAQuarter( const vector<vector<bool>>& matrix, int row, int column, int m);
    	// Pre: matriz 2^n x 2^n
    	// Post: devuelve el cuarto de matriz formado desde la posición (fila, columna) con tamaño n/2
    	// O(m^2) donde m es el tamaño de la submatriz
    	
    	// Escritura
    	void escribe();
    	void escribeAux( TNodoQuad* p, string prefijo);
    	
    private:
    	
    	TNodoQuad* _ra;
    	TArbQuad(TNodoQuad*);
    	
 };
 
 // Operaciones básicas del árbol y constructoras
 
 TNodoQuad::TNodoQuad( char color, TNodoQuad* a1, TNodoQuad* a2, TNodoQuad* a3, TNodoQuad* a4):
 	_color(color), _a1(a1), _a2(a2), _a3(a3), _a4(a4) {};
 	
 char& TNodoQuad::color() {return _color;}
 
 TNodoQuad* TNodoQuad::a1() {return _a1;}
 TNodoQuad* TNodoQuad::a2() {return _a2;}
 TNodoQuad* TNodoQuad::a3() {return _a3;}
 TNodoQuad* TNodoQuad::a4() {return _a4;}
 TArbQuad::TArbQuad( TNodoQuad* ra):_ra(ra) {};
 TArbQuad::TArbQuad():_ra(0) {};
 bool TArbQuad::esVacio() {return _ra==0;};
 
 // Ejercicios
 
 TArbQuad TArbQuad::blanco() {
 	
 	TArbQuad arbol;
 	arbol._ra = new TNodoQuad('B', 0, 0, 0, 0);
 	return arbol;
 	
 }
 
 TArbQuad TArbQuad::negro() {
 	
 	TArbQuad arbol;
 	arbol._ra = new TNodoQuad('N', 0, 0, 0, 0);
 	return arbol;
 	
 }
 
 TArbQuad TArbQuad::plantar( const TArbQuad& a1, const TArbQuad& a2, const TArbQuad& a3, const TArbQuad& a4) {
 	
 	char monocolor = a1._ra -> color();
 	
 	if (monocolor != 'I' && a2._ra -> color() == monocolor && a3._ra -> color() == monocolor && a4._ra -> color() == monocolor) {
 		
 		if( monocolor == 'B')
 		
 			return blanco();
 		
 		else
 		
 			return negro();
 			
	 }
	 
	 else {
	 	
	 	TArbQuad arbol;
	 	arbol._ra = new TNodoQuad('I', a1._ra, a2._ra, a3._ra, a4._ra);
	 	return arbol;
	 	
	 }
	 
 }
 
 bool TArbQuad::esBlanco() {
 	
 	if(esVacio())
 		
 		return false;
 	
 	return _ra -> color() == 'B';
 	
 }
 
 bool TArbQuad::esNegro() {
 	
 	if(esVacio())
 		
 		return false;
 	
 	return _ra -> color() == 'N';
 	
 }
 
 TArbQuad TArbQuad::hijo(int n) {
 	
 	TArbQuad arbol;
 	
 	if( _ra -> _color == 'I') {
 		
 		if( n == 1) arbol._ra = _ra -> a1();
 		if( n == 2) arbol._ra = _ra -> a2();
 		if( n == 3) arbol._ra = _ra -> a3();
 		if( n == 4) arbol._ra = _ra -> a4();
 		
	 }
	 
	 else {
	 	
	 	arbol._ra = _ra;
	 	
	 }
	 
	 return arbol;
 	
 }
 
 TArbQuad TArbQuad::negativo()  {
 	
 	if(esVacio()) return _ra;
 	if(esBlanco()) return negro();
 	if(esNegro()) return blanco();
 	
 	else {
 		
 		TArbQuad arbol;
 		TArbQuad _1a = hijo(1).negativo();
 		TArbQuad _2a = hijo(2).negativo();
 		TArbQuad _3a = hijo(3).negativo();
 		TArbQuad _4a = hijo(4).negativo();
 		
 		arbol = plantar(_1a, _2a, _3a, _4a);
 		return arbol;
 		
	 }
	 
 }
 
 TArbQuad TArbQuad::matriztoArb(vector<vector<bool>> matrix) {
 	
 	int n = matrix.size();
 	if(matrix.empty()) return TArbQuad();
 	if( n == 1 && matrix[0][0] == true) return blanco();
 	if( n == 1 && matrix[0][0] == false) return negro();
 	
 	else {
 		
 		TArbQuad arbol = plantar(matriztoArb(getAQuarter(matrix, 0, 0, n/2)),
 								 matriztoArb(getAQuarter(matrix, 0, n/2, n/2)),
 								 matriztoArb(getAQuarter(matrix, n/2, 0, n/2)),
 								 matriztoArb(getAQuarter(matrix, n/2, n/2, n/2)));
 		
 		return arbol;
 		
	 }
	 
 }
 
vector<vector<bool>> TArbQuad::getAQuarter( const vector<vector<bool>>& matrix, int row, int column, int m) {
	
	vector<vector<bool>> quarter(m, vector<bool>(m));
	
	for( int i = 0; i < m; i++) {
		
		for(int j = 0; j < m; j++) {
			
			quarter[i][j] = matrix[row + i][column + j];
		}
		
	}
	
	return quarter;
	
}
 
 // Operaciones de escritura
 
 void TArbQuad::escribeAux( TNodoQuad* p, string prefijo) {
 	
 	if( p != 0) {
 		
 		cout << (prefijo +" : ") << p -> color() << endl;
 		
 		escribeAux(p -> a1(), prefijo + ".1");
 		escribeAux(p -> a2(), prefijo + ".2");
 		escribeAux(p -> a3(), prefijo + ".3");
 		escribeAux(p -> a4(), prefijo + ".4");
 		
	 }
	 
 }
 
 void TArbQuad::escribe() {
 	
 	cout << endl;
 	
 	escribeAux(_ra, "1");
 	
 }