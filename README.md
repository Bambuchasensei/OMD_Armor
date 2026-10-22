# OMD Armor

Иммерсивная баллистическая защита для бронежилетов: пуля останавливается или пробивает в зависимости от класса защиты, класса патрона и износа жилета.

![DayZ](https://img.shields.io/badge/DayZ-1.2x-red)
![Enforce Script](https://img.shields.io/badge/language-Enforce%20Script-blue)
![Status](https://img.shields.io/badge/status-in%20development-orange)

> **TL;DR (EN):** An immersive firearm-protection system for DayZ body armor. Instead of a flat vanilla damage multiplier, each hit is resolved by hit zone (front/back/side), protection class of that zone, ammo class and vest wear: the bullet is either **stopped** (blunt trauma only) or **penetrates** and continues into the OMD damage model. Adds 10 armor plates (RU GOST Br4–Br6, US Level III–IV, ESAPI/XSAPI) with dedicated vest slots, plus hit sound and spark effects. Written in Enforce Script.

## Возможности

- **«Остановил или пробил» вместо простого множителя урона.** Попадание из огнестрела разбирается по зоне (грудь, спина, бок — по направлению пули), классу защиты зоны и классу патрона. Если защита держит, урон игроку отменяется и остаётся только тупая травма; если пробивает, урон идёт дальше в модель повреждений `OMD_NewDamage`.
- **Износ влияет на защиту.** Класс плиты постепенно снижается по мере повреждения жилета, а не пропадает только когда жилет испорчен.
- **Бронеплиты:** 10 плит — российские по ГОСТ (сталь Бр4, керамика Бр4/Бр5, композит Бр5, сталь Бр6) и американские (сталь Level III, керамика Level III+ и Level IV, ESAPI, XSAPI). Слоты для передней и задней плиты у жилетов, с отдельными иконками.
- **Зоны без защиты учитываются честно:** руки, бёдра, голова и шея не прикрываются жилетом, даже если в ванили они относятся к зоне `Torso`.
- **Обратная связь без цифр на HUD:** звук попадания в плиту и искры при остановке/пробитии.
- Затрагивается только огнестрел; ближний бой, заражённые и осколки остаются на ванильной защите.

## Требования

- DayZ (клиент и сервер)
- [OMD Bridge](https://github.com/Bambuchasensei/OMD_Bridge)
- [OMD NewDamage](https://github.com/Bambuchasensei/OMD_NewDamage)
- Terje: `TerjeMedicine` (и его зависимости)

## Установка

1. Подпишитесь на зависимости и на этот мод.
2. Добавьте мод в `-mod=` клиента и сервера после `OMD_Bridge` и `OMD_NewDamage`.
3. Серверная логика расчёта попаданий вынесена в отдельный приватный репозиторий (`OMD_Armor_Server`) и ставится только на сервер.

## Конфигурация

Параметры баланса (классы защиты зон, таблица «патрон → класс пробития» и др.) задаются в JSON-файле в папке профиля сервера (`%profile%/omd/OMD_Armor.json`). Подробный дизайн системы — в [docs/design_armor.md](docs/design_armor.md).

## Структура проекта

```
OMD_Armor/
├── config.cpp          # CfgPatches, слоты плит, классы плит, параметры жилетов
├── data/
│   ├── plates/         # модель, текстуры и материалы плит
│   └── imagesets/      # иконки слотов
├── docs/
│   └── design_armor.md # дизайн-документ системы
└── Scripts/
    └── 4_World/        # клиентские эффекты попаданий (звук, искры)
```

## Скриншоты

<!-- TODO: добавить скриншоты (docs/images/...) -->
_Скоро._

## Steam Workshop

<!-- TODO: ссылка на мастерскую Steam -->
_Мод пока не опубликован в мастерской._

## Автор

**Bambuchasensei** — разработка и дизайн механик для сообщества и сервера **One More DayZ (OMD)**.

## Лицензия

All rights reserved. Код и ассеты опубликованы для ознакомления (портфолио). Использование, копирование и перезалив — только с разрешения автора.