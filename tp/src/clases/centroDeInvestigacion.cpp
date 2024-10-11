#include <string>

class CentroInvestigacion {
private:
    std::string codigo;
    std::string nombre;
    std::string ciudad;
    std::string pais;
    float superficie;
    int num_laboratorios;
    int proyectos_nacionales;
    int proyectos_internacionales;

public:
    CentroInvestigacion(const std::string& codigo, const std::string& nombre,
                        const std::string& ciudad, const std::string& pais,
                        float superficie, int num_laboratorios,
                        int proyectos_nacionales, int proyectos_internacionales)
        : codigo(codigo), nombre(nombre), ciudad(ciudad), pais(pais),
          superficie(superficie), num_laboratorios(num_laboratorios),
          proyectos_nacionales(proyectos_nacionales), proyectos_internacionales(proyectos_internacionales) {}

    std::string getCodigo() const { return codigo; }
    std::string getNombre() const { return nombre; }
    std::string getCiudad() const { return ciudad; }
    std::string getPais() const { return pais; }
    float getSuperficie() const { return superficie; }
    int getNumLaboratorios() const { return num_laboratorios; }
    int getProyectosNacionales() const { return proyectos_nacionales; }
    int getProyectosInternacionales() const { return proyectos_internacionales; }
};

