
# 📘 Stage4 - Generación de Javadoc

Este proyecto utiliza Maven para compilar, ejecutar y generar la documentación del código fuente. A continuación se describen los pasos para generar la documentación Javadoc **solo para clases seleccionadas**.

## ✅ Clases incluidas en la documentación

El perfil `custom-javadoc` genera documentación **solo para las siguientes clases**:

- `Component.java`
- `Publisher.java`
- `Subscriber.java`
- `Broker.java`
- `Topic.java`

---

## 📦 Requisitos previos

- Java 21 instalado (o compatible con el proyecto)
- Maven instalado (versión 3.6+ recomendada)
- Tener configurado el entorno con variables `JAVA_HOME` y `MAVEN_HOME` correctamente
- Acceso a internet para descargar dependencias

---

## 📝 Instrucciones paso a paso

### 1. Clonar o descargar el proyecto

```bash
git clone <url-del-repositorio>
cd Stage4
```

### 2. Verifica que Maven funciona

```bash
mvn -v
```

Deberías ver información de la versión de Maven y del JDK configurado.

### 3. Ejecutar el perfil `custom-javadoc`

```bash
mvn javadoc:javadoc -Pcustom-javadoc
```

> ☑️ Este perfil se encarga de incluir solo los archivos relevantes definidos en el `pom.xml`.

### 4. Ver la documentación generada

Una vez completada la ejecución, abre el archivo principal del Javadoc:

```bash
doc/index.html
```

Puedes abrirlo con cualquier navegador:

```bash
xdg-open doc/index.html     # Linux
start doc\index.html        # Windows
open doc/index.html         # macOS
```

---

## ❓ Problemas comunes

- **"Aggregator report contains named and unnamed modules"**  
  Este error no ocurre con este perfil, ya que se evita incluir clases con problemas de módulos JavaFX.

- **Módulos de JavaFX no encontrados**  
  No es un problema aquí, ya que este perfil solo documenta clases sin dependencias visuales.

---

## 🧼 Limpieza (opcional)

Si deseas eliminar la carpeta de documentación generada:

```bash
rm -r doc                  # Linux/macOS
rmdir /s /q doc            # Windows
```

---

## 📁 Estructura esperada de salida

```
Stage4/
├── pom.xml
├── src/
│   └── main/java/com/example/stage4/...
├── doc/
│   ├── index.html
│   └── ... (otros archivos de documentación)
```

---

## 📌 Notas

- Este perfil es independiente y no requiere definir un `module-info.java`.
- Puedes modificar las rutas dentro del perfil `custom-javadoc` si agregas o eliminas clases.
