# Devlog

### 📅 Début du projet
Le projet n’a **pas** démarré le *19/10/2025*, mais en réalité le **16/10/2025**.

---

## 🧩 19/10/2025 — Update

### 🔹 Ajout du support des LED PIN
- Ajout du support des LED PIN pour **Caps Lock**, **WinLock** et **Mac Mode**  
- **Pins utilisées** : `C4`, `B9`, `B8`

### 🔹 Support VIA
- Ajout du **support VIA** (`Keymaps/via`)  
- Fichier de configuration : `via.json`

### 🔹 LEDs carte mère
- Ajout du **support des LEDs sur la carte mère**
- Compatibilité **VIA**
- **Personnalisation complète** des effets disponibles

---

## 🧩 20/10/2025 — Update

### 🌈 Animation RGB au démarrage
- Ajout d’une **animation RGB** lors du démarrage du clavier

### 💡 Contrôles RGB via raccourcis clavier

| Raccourci  |          Fonction           |   Code    |
|------------|-----------------------------|-----------|
| Fn + ESC   | Activer/Désactiver les LEDs | `RM_TOGG` |
| Fn + &     | Effet suivant               | `RM_NEXT` |
| Fn + -     | Effet précédent             | `RM_PREV` |
| Fn + é     | Augmenter la teinte (Hue)   | `RM_HUEU` |
| Fn + z     | Diminuer la teinte (Hue)    | `RM_HUED` |
| Fn + (     | Augmenter la vitesse        | `RM_SPDU` |
| Fn + T     | Diminuer la vitesse         | `RM_SPDD` |
| Fn + "     | Augmenter la saturation     | `RM_SATU` |
| Fn + E     | Diminue la Saturation       | `RM_VALD` |
| Fn + '     | Augmenter la luminosité     | `RM_VALU` |
| Fn + R     | Diminuer la luminosité      | `RM_VALD` |
| Fn + Space | Réinitialiser l’EEPROM      | `EE_CLR`  |

---

### 🛠️ Correctifs
- Correction de la touche `*` non fonctionnelle  
  → Remplacement de `FR_ASTR` par `KC_NUHS`  
  → Ajout de la touche dans la matrice (`keyboard.json`)

## 🧩 21/10/2025 — Update

Idée de rendre compatible le clavier compatible avec SignalRGB pour plus tard faire un effect Ambilight avec un plugin (SignalRGB Supporte QMK Firmware)
Idée de crée des animation VIA personnalisé dans `/animations`



