# 🎹 Royal Kludge R75 — Firmware QMK Custom

Bienvenue sur le dépôt du firmware QMK personnalisé pour le clavier **Royal Kludge R75** (Version ISO FR / AZERTY).

Ce projet vise à fournir un firmware complet, stable et riche en fonctionnalités pour exploiter tout le potentiel du RK75 avec QMK et VIA.

## 📋 Caractéristiques

### ⚙️ Matériel

*   **Processeur** : WB32FQ95
*   **Bootloader** : wb32-dfu
*   **Layout** : ISO FR (75% avec encodeur rotatif)
*   **RGB Matrix** : 83 LEDs WS2812 (SPI)
*   **Encodeur rotatif** : 1x (pins B7/B6)
*   **Indicateurs LED** : Caps Lock, Win Lock, Mac Mode

### ✨ Fonctionnalités

#### 🌈 RGB Matrix

*   **83 LEDs** adressables individuellement
*   **40+ effets d'animation** inclus (breathing, rainbow, reactive, typing heatmap, etc.)
*   **Animation de démarrage** personnalisée (rainbow wave)
*   Support des effets réactifs aux touches
*   Configuration complète via VIA

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

*   **Win Lock** : `Fn + Win` — Désactive la touche Windows
*   **Mac Mode** : `Fn + A` — Bascule en mode Mac
*   **Reset EEPROM** : `Fn + Space` — Réinitialise la configuration
*   **Bootloader** : `Fn + Mute` — Entre en mode flash

#### 🎛️ Support VIA

*   Configuration en temps réel via [VIA](https://usevia.app/)
*   Remapping des touches sans recompilation
*   Sauvegarde des paramètres RGB en EEPROM
*   Macros et layers personnalisables

## 🚀 Installation et Compilation

### Prérequis

*   [QMK MSYS](https://msys.qmk.fm/) (Windows) ou QMK CLI (Linux/macOS).
*   Drivers WB32 (si nécessaire pour le flashage).

### Instructions de Build

1.  **Cloner ce dépôt** dans votre dossier `qmk_firmware/keyboards/` :
    ```bash
    mkdir -p ~/qmk_firmware/keyboards/rk
    git clone https://github.com/votre-repo/rk75.git ~/qmk_firmware/keyboards/rk/r75
    ```

2.  **Compiler le firmware** :
    
    Pour la version par défaut :
    ```bash
    qmk compile -kb rk/r75 -km default
    ```

    Pour la version compatible VIA (recommandé) :
    ```bash
    qmk compile -kb rk/r75 -km via
    ```

### Flash

1.  Passez le clavier en mode **Bootloader** : Maintenez `Fn + Mute` (ou utilisez le bouton reset sous la barre espace si accessible).
2.  Flashez le fichier `.bin` généré avec QMK Toolbox ou la commande :
    ```bash
    qmk flash -kb rk/r75 -km via
    ```

## 📁 Structure du Projet

Le code source spécifique à ce clavier se trouve dans le répertoire `keyboard/rk/r75/` :

*   `config.h` : Configuration matérielle.
*   `keyboard.json` : Définition de la matrice et du layout.
*   `keymaps/` : Dossier contenant les keymaps (`default`, `via`).
*   `rules.mk` : Options de compilation QMK.

## 🐛 Dépannage

### Le clavier n'est pas détecté
*   Vérifiez que les drivers WB32 sont installés
*   Essayez un autre câble USB

### Les LEDs ne s'allument pas
*   Vérifiez que le pin A5 (LED_ENABLE_PIN) est correctement configuré
*   Testez avec `Fn + ESC` pour toggle les LEDs

### VIA ne détecte pas le clavier
*   Assurez-vous d'avoir flashé le keymap `via`
*   Importez `keymaps/via/via.json` dans VIA si nécessaire

## 🤝 Contribution

Les contributions sont les bienvenues ! Voir [Devlog.md](keyboard/rk/r75/Devlog.md) pour l'historique des changements.

## 👤 Auteur

**iSweat**

---

### 💡 Petite anecdote

Ce projet a initialement été créé parce que j'ai cassé le firmware de mon clavier 15 minutes après l'avoir reçu (Royal Kludge ne fournit que le firmware pour la version ANSI US et non la version ISO FR) alors je l'ai développé moi-même, et terminé la base en 4 jours. Le reste, c'est tout simplement l'envie de faire un beau projet.
