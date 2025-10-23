# Space Mouse Arduino 🖱️

Projet de Space Mouse DIY basée sur Arduino Nano 32u4, permettant de contrôler les mouvements 3D dans Fusion 360 à l'aide d'un joystick analogique.

## 📋 Description

Ce projet transforme un Arduino Nano (avec puce 32u4) et un joystick en une Space Mouse fonctionnelle pour la navigation 3D dans les logiciels de modélisation comme Fusion 360. Le dispositif permet de manipuler les modèles 3D (rotation, zoom, déplacement) de manière intuitive.

## ✨ Fonctionnalités

- **Navigation 3D** : Contrôle des mouvements sur les axes X et Y
- **Émulation souris** : Utilisation des bibliothèques Mouse et Keyboard Arduino
- **Interface USB** : Connexion directe via USB HID
- **Personnalisable** : Code facilement modifiable pour adapter la sensibilité

## 🔧 Matériel nécessaire

- Arduino Nano avec puce **32u4** (Leonardo, Pro Micro ou compatible)
- Joystick analogique 2 axes avec bouton
- PCB custom (fichiers DXF fournis)
- Boîtier imprimé en 3D (fichiers STL fournis)
- Câbles de connexion
- LED indicateur de statut (optionnel)

## 📁 Structure du projet

```
├── space-mouse.ino              # Programme principal
├── space_Mouse-test.ino         # Programme de test et calibration
├── pcb/
│   └── *.dxf                    # Fichiers DXF pour le PCB
├── 3d-models/
│   └── *.stl                    # Modèles 3D pour le boîtier
└── datasheets/
    └── *.pdf                    # Datasheets des composants
```

## 🔌 Schéma de câblage

| Composant | Pin Arduino |
|-----------|-------------|
| Axe X du joystick | A0 |
| Axe Y du joystick | A1 |
| Bouton du joystick | D9 |
| LED de statut | D2 |

## 🚀 Installation

### 1. Prérequis logiciels

- [Arduino IDE](https://www.arduino.cc/en/software) (version 1.8.x ou supérieure)
- Bibliothèques Arduino (incluses par défaut avec les cartes 32u4) :
  - `Mouse.h`
  - `Keyboard.h`

### 2. Configuration de l'Arduino IDE

1. Ouvrir Arduino IDE
2. Aller dans **Outils → Type de carte** et sélectionner votre carte 32u4
3. Sélectionner le port COM approprié dans **Outils → Port**

### 3. Upload du code

#### Test et calibration (recommandé en premier)
```arduino
// Ouvrir space_Mouse-test.ino
// Uploader sur l'Arduino
// Ouvrir le moniteur série (9600 baud)
// Noter les valeurs au repos du joystick
```

#### Programme principal
```arduino
// Ouvrir space-mouse.ino
// Ajuster les valeurs de seuil si nécessaire (lignes 47-48)
// Uploader sur l'Arduino
```

## ⚙️ Calibration

Les valeurs par défaut au repos sont :
- **Axe X** : ~500
- **Axe Y** : ~519

Seuils de détection (ajustables dans le code) :
- **Seuil haut** : ≥ 600
- **Seuil bas** : ≤ 400

Pour calibrer votre joystick :
1. Uploadez `space_Mouse-test.ino`
2. Ouvrez le moniteur série
3. Notez les valeurs au repos
4. Ajustez les seuils dans `space-mouse.ino` en conséquence

## 🎮 Utilisation

1. Connecter la Space Mouse via USB
2. Ouvrir Fusion 360 ou un autre logiciel de modélisation 3D
3. Utiliser le joystick pour :
   - **Gauche/Droite** : Rotation autour de l'axe vertical
   - **Haut/Bas** : Rotation autour de l'axe horizontal
   - **Bouton** : Changement de mode (zoom/déplacement)

## 🛠️ Fabrication

### PCB
Les fichiers DXF sont disponibles dans le dossier `pcb/`. Vous pouvez les utiliser pour :
- Fraiser un PCB
- Commander des PCB chez un fabricant (JLCPCB, PCBWay, etc.)

### Boîtier 3D
Les modèles STL sont disponibles dans le dossier `3d-models/`. Paramètres d'impression recommandés :
- **Hauteur de couche** : 0.2mm
- **Remplissage** : 20%
- **Supports** : Si nécessaire
- **Matériau** : PLA ou PETG

## 📚 Documentation technique

Les datasheets des composants utilisés sont disponibles dans le dossier `datasheets/`.

## 🐛 Dépannage

### L'Arduino n'est pas reconnu
- Vérifiez que vous utilisez bien une carte avec puce **32u4**
- Installez les drivers appropriés pour votre système

### Les mouvements sont trop sensibles/pas assez
- Ajustez les valeurs de `map()` dans le code (ligne 49-50 du test)
- Modifiez les valeurs de `Mouse.move()` (5, 10, 20, etc.)

### Le joystick dérive
- Recalibrez en ajustant les seuils bas et haut
- Vérifiez les connexions électriques

## 📝 Licence

Ce projet est open source. Vous êtes libre de le modifier et de le redistribuer.

## 🤝 Contributions

Les contributions sont les bienvenues ! N'hésitez pas à :
- Ouvrir des issues pour signaler des bugs
- Proposer des améliorations via pull requests
- Partager vos modifications et améliorations

## 📧 Contact

Pour toute question ou suggestion, n'hésitez pas à ouvrir une issue sur ce repository.

---

**Note** : Ce projet est conçu pour un usage éducatif et personnel. Les Space Mouse commerciales offrent des fonctionnalités plus avancées (6 degrés de liberté).

## 🎯 Améliorations futures

- [ ] Ajout d'un troisième axe de rotation
- [ ] Support pour d'autres logiciels 3D
- [ ] Mode de sensibilité ajustable via potentiomètre
- [ ] Boutons supplémentaires pour des raccourcis
- [ ] Support sans fil (Bluetooth)