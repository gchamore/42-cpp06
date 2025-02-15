# 🔄 C++ - Module 06

## 📝 Présentation

Le module **C++ 06** introduit les **castings en C++**, notamment les **conversions de types scalaires**, la **sérialisation**, et l’**identification de types à l'exécution**.  
L'objectif est d'apprendre à manipuler et convertir des types en C++ tout en respectant les contraintes du langage.

---

## 🛠️ Fonctionnalités

- **Exercice 00 : Conversion de types scalaires**
  - Implémentation d'une classe `ScalarConverter` contenant une méthode statique `convert()`.
  - Détection du type d’un **littéral passé en paramètre** (`char`, `int`, `float`, `double`).
  - Gestion des **pseudo-littéraux** (`nan`, `-inf`, `+inf`, etc.).
  - Affichage du résultat sous **différents types scalaires**.
  - Gestion des conversions impossibles avec des **messages d'erreur**.

- **Exercice 01 : Sérialisation**
  - Implémentation d’une classe `Serializer` avec deux méthodes statiques :
    - `uintptr_t serialize(Data* ptr);` : Convertit un pointeur en `uintptr_t`.
    - `Data* deserialize(uintptr_t raw);` : Convertit un `uintptr_t` en pointeur `Data*`.
  - Test de cohérence : après sérialisation et désérialisation, le pointeur doit être **identique** à l’original.

- **Exercice 02 : Identification du type réel**
  - Création d’une classe **abstraite** `Base` avec un **destructeur virtuel**.
  - Implémentation de trois classes `A`, `B`, `C` héritant de `Base`.
  - Fonction `Base * generate(void);` qui crée aléatoirement une instance de `A`, `B` ou `C`.
  - Fonction `void identify(Base* p);` qui affiche le **type réel de l’objet** pointé.
  - Fonction `void identify(Base& p);` qui **affiche le type sans utiliser de pointeur**.
  - **Interdiction d’utiliser `std::typeinfo` (`typeid()`).**

---

## 📌 Technologies Utilisées

- **C++ 98**  
- **C++ casts (`static_cast`, `reinterpret_cast`, etc.)**  
- **Conversions de types (scalaires et objets)**  
- **Sérialisation et manipulation de pointeurs**  
- **Héritage et identification dynamique de types**  

---

## 🏗️ Structure du Projet

📂 ex00  
┣ 📜 Makefile  
┣ 📜 ScalarConverter.cpp  
┣ 📜 ScalarConverter.hpp  
┗ 📜 main.cpp  

📂 ex01  
┣ 📜 Makefile  
┣ 📜 Serializer.cpp  
┣ 📜 Serializer.hpp  
┗ 📜 main.cpp  

📂 ex02  
┣ 📜 A.cpp  
┣ 📜 A.hpp  
┣ 📜 B.cpp  
┣ 📜 B.hpp  
┣ 📜 Base.cpp  
┣ 📜 Base.hpp  
┣ 📜 C.cpp  
┣ 📜 C.hpp  
┣ 📜 Makefile  
┣ 📜 main.cpp  
┗ 📜 doc.txt  


---

## 🔥 Difficultés Rencontrées

- **Détection correcte des types scalaires (`char`, `int`, `float`, `double`)**.  
- **Gestion des exceptions et conversions impossibles** (`overflow`, valeurs non affichables).  
- **Utilisation de `reinterpret_cast` et `uintptr_t` pour sérialiser des pointeurs**.  
- **Implémentation correcte du `dynamic_cast` sans `std::typeinfo`**.  
- **Génération aléatoire et identification correcte des classes `A`, `B`, `C`**.  

---

## 🏗️ Mise en place

1. **Cloner le dépôt** :  
  ```bash
  git clone https://github.com/ton-repo/cpp06.git
  cd cpp06
  ```

2. **Compiler et exécuter chaque exercice** :

**Exercice 00** :   
   ```bash
   cd ex00
   make
   ./convert 42.0f
   make fclean
   ```

**Exercice 01** :  
  ```bash
   cd ex01
   make
   ./serializer
   make fclean
   ```

**Exercice 02** :  
   ```bash
   cd ex02
   make
   ./identify
   make fclean
   ```

---

## 👨‍💻 Équipe  

👤 Grégoire Chamorel (Gchamore)  

---

## 📜 Projet réalisé dans le cadre du cursus 42.  

Tu peux bien sûr modifier ce README selon tes besoins, ajouter plus de détails sur ton approche et des instructions d’installation précises. 🚀  
