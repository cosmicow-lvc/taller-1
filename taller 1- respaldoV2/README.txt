EQUIPO:
Maximo Jofre Letelier; 21675371-2; maximo.jofre@alumnos.ucn.cl; C-2
Antonio Tabilo; 21668377-3; antonio.tabilo@alumnos.ucn.cl; C-2 

Objetos:

MaterialBibliografico:

    Atributos:

    String nombre
    String isbn
    String autor
    bool prestamo

    Métodos:

    MaterialBibliografico(String nombre, String isbn, String autor, bool prestamo) {constructor}
    Destructor
    Getters y Setters
    void virtual mostrarInformacion(): Método que muestra por pantalla los atributos del objeto.

Libro (hereda de MaterialBibliografico):

    Descripción: El objeto Libro representa un material bibliográfico específico que hereda de 
    MaterialBibliografico.

    Atributos adicionales:

    String fechaPublicacion
    String resumen

    Métodos:

    Libro(String nombre, String isbn, String autor, bool prestamo, int numeroPaginas, String editorial) {constructor}
    Destructor
    Getters y Setters
    void mostrarInformacion() overrride

Revista (hereda de MaterialBibliografico):

    Descripción: El objeto Revista representa un material bibliográfico específico que hereda de 
    MaterialBibliografico.

    Atributos adicionales:

    String numeroPublicacion
    String mesPublicacion

    Métodos:

    Revista(String nombre, String isbn, String autor, bool prestamo, string numeroPublicacion, string mesPublicacion)
    Destructor
    Getters y Setters
    void mostrarInformacion() overrride

Usuario:

    Atributos:

    String nombre
    String id

    Métodos:

    Usuario(string nombre, string id)
    Destructor
    Getters y Setters
    void prestarMaterial(MaterialBibliografico* material)
    void devolverMaterial(String palabra, String criterio)
    void mostrarMaterialesPrestados()
    void mostrarInformacionUsuario()

    
