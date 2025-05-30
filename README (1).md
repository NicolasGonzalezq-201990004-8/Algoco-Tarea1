
## Generación de Javadoc

Este proyecto utiliza Maven para compilar, ejecutar y generar la documentación del código fuente. A continuación se describen los pasos para generar la documentación Javadoc **solo para clases seleccionadas**.

Clases incluidas en la documentación

El perfil `custom-javadoc` genera documentación **solo para las siguientes clases**:

- `Component.java`
- `Publisher.java`
- `GPSCarPublisher`

---

## Requisitos previos

- Java 21 o superior instalado 
- Maven instalado (versión 3.6+ recomendada)
- Tener configurado el entorno con variables `JAVA_HOME` y `MAVEN_HOME` correctamente
- Acceso a internet para descargar dependencias

---

## Instrucciones

### 1. Clonar o descargar el proyecto

```bash
git clone <url-del-repositorio>
cd Stage4
```

### 2. Verificar funcionamiento de Maven

```bash
mvn -v
```

### 3. Ejecutar el perfil `custom-javadoc`

```bash
mvn javadoc:javadoc -Pcustom-javadoc
```

Este perfil se encarga de incluir solo los archivos relevantes definidos en `pom.xml`.

### 4. Ver la documentación generada

Una vez completada la ejecución, abre el archivo principal del Javadoc:

```bash
doc/index.html
```
---

