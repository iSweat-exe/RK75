# 🎹 Royal Kludge R75 — Firmware QMK Custom

Firmware QMK personnalisé pour le clavier **Royal Kludge R75** en disposition **ISO FR** (AZERTY).

## 📋 Caractéristiques

### ⚙️ Matériel

-   **Processeur** : WB32FQ95
-   **Bootloader** : wb32-dfu
-   **Layout** : ISO FR (75% avec encodeur rotatif)
-   **RGB Matrix** : 83 LEDs WS2812 (SPI)
-   **Encodeur rotatif** : 1x (pins B7/B6)
-   **Indicateurs LED** : Caps Lock, Win Lock, Mac Mode

### ✨ Fonctionnalités

#### 🌈 RGB Matrix

-   **83 LEDs** adressables individuellement
-   **40+ effets d'animation** inclus (breathing, rainbow, reactive, typing heatmap, etc.)
-   **Animation de démarrage** personnalisée (rainbow wave)
-   Support des effets réactifs aux touches
-   Configuration complète via VIA

#### 🎮 Contrôles RGB (Layer Fn)

| Raccourci  | Fonction               | Code      |
| ---------- | ---------------------- | --------- |
| `Fn + ESC` | Toggle RGB ON/OFF      | `RM_TOGG` |
| `Fn + &`   | Effet suivant          | `RM_NEXT` |
| `Fn + -`   | Effet précédent        | `RM_PREV` |
| `Fn + é`   | Augmenter teinte (Hue) | `RM_HUEU` |
| `Fn + z`   | Diminuer teinte (Hue)  | `RM_HUED` |
| `Fn + (`   | Augmenter vitesse      | `RM_SPDU` |
| `Fn + T`   | Diminuer vitesse       | `RM_SPDD` |
| `Fn + "`   | Augmenter saturation   | `RM_SATU` |
| `Fn + E`   | Diminuer saturation    | `RM_SATD` |
| `Fn + '`   | Augmenter luminosité   | `RM_VALU` |
| `Fn + R`   | Diminuer luminosité    | `RM_VALD` |

#### 🔧 Fonctions avancées

-   **Win Lock** : `Fn + Win` — Désactive la touche Windows
-   **Mac Mode** : `Fn + A` — Bascule en mode Mac
-   **Reset EEPROM** : `Fn + Space` — Réinitialise la configuration
-   **Bootloader** : `Fn + Mute` — Entre en mode flash

#### 🎛️ Support VIA

-   Configuration en temps réel via [VIA](https://usevia.app/)
-   Remapping des touches sans recompilation
-   Sauvegarde des paramètres RGB en EEPROM
-   Macros et layers personnalisables

## 🚀 Installation

### Prérequis

-   [QMK Toolbox](https://github.com/qmk/qmk_toolbox) ou [QMK CLI](https://docs.qmk.fm/#/newbs_getting_started)
-   Drivers WB32 installés

### Compilation

```bash
# Cloner le dépôt dans votre environnement QMK
cd ~/qmk_firmware/keyboards/
git clone <ce-repo> rk/r75

# Compiler le firmware (keymap par défaut)
qmk compile -kb rk/r75 -km default

# Compiler avec support VIA
qmk compile -kb rk/r75 -km via
```

### Flash

1. Maintenir `Fn + Mute` pour entrer en mode bootloader
2. Flasher avec QMK Toolbox ou :

```bash
qmk flash -kb rk/r75 -km via
```

## 📁 Structure du projet

```
.
├── animations/          # Animations RGB personnalisées
├── keymaps/
│   ├── default/        # Keymap par défaut
│   └── via/            # Keymap avec support VIA
├── config.h            # Configuration matérielle
├── keyboard.json       # Définition du clavier (pins, matrix, RGB)
├── r75.c               # Code principal du clavier
├── rgb_startup_animation.c  # Animation de démarrage
├── rules.mk            # Options de compilation
└── README.md           # Ce fichier
```

## 🎨 Personnalisation

### Modifier l'animation de démarrage

Éditez `rgb_startup_animation.c` pour personnaliser l'effet au boot.

### Ajouter des animations custom

Placez vos animations dans le dossier `animations/` et incluez-les dans `rules.mk`.

### Modifier le layout

Le fichier `keyboard.json` contient la définition complète de la matrice et des positions RGB.

## 🐛 Dépannage

### Le clavier n'est pas détecté

-   Vérifiez que les drivers WB32 sont installés
-   Essayez un autre câble USB

### Les LEDs ne s'allument pas

-   Vérifiez que le pin A5 (LED_ENABLE_PIN) est correctement configuré
-   Testez avec `Fn + ESC` pour toggle les LEDs

### VIA ne détecte pas le clavier

-   Assurez-vous d'avoir flashé le keymap `via`
-   Importez `keymaps/via/via.json` dans VIA si nécessaire

## 📝 Changelog

Consultez [Devlog.md](Devlog.md) pour l'historique détaillé des modifications.

## 🔮 Roadmap

-   [ ] Support SignalRGB pour effets Ambilight
-   [ ] Animations VIA personnalisées supplémentaires
-   [ ] Profils RGB sauvegardables

## 👤 Auteur

**iSweat**

Ce projet est développé sur mon temps libre et sera mis à jour selon les besoins et les retours de la communauté.

## 🤝 Contributions

Les contributions sont les bienvenues ! N'hésitez pas à :

-   Ouvrir une issue pour signaler un bug
-   Proposer des améliorations via pull request
-   Partager vos animations RGB personnalisées
-   Améliorer la documentation

## 📄 Licence

Ce projet est basé sur [QMK Firmware](https://github.com/qmk/qmk_firmware) et suit la licence GPL v2.

---

### 💡 Petite anecdote

Ce projet a initialement été créé parce que j'ai cassé le firmware de mon clavier 15 minutes après l'avoir reçu (Royal Kludge ne fournit que le firmware pour la version ANSI US et non la version ISO FR) alors je l'ai développé moi-même, et terminé la base en 4 jours. Le reste, c'est tout simplement l'envie de faire un beau projet.
