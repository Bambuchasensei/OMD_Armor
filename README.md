# OMD Armor

Иммерсивная баллистическая защита для бронежилетов: плиты останавливают, «трескаются» или пропускают пулю в зависимости от своего оставшегося ресурса.

![Version](https://img.shields.io/badge/version-0.1.0-blue)
![Status](https://img.shields.io/badge/status-in%20development-orange)
![Enforce Script](https://img.shields.io/badge/language-Enforce%20Script-blue)

> **TL;DR (EN):** An immersive firearm-protection system for DayZ body armor. A hit on an intact chest/back plate results in **STOP**, **CRACK** or **PEN** depending on the plate's remaining HP. STOP and CRACK cancel the vanilla hit and apply blunt-impact shock instead; PEN lets reduced damage through into the OMD damage model. Plates wear down. Adds 10 armor plates (RU GOST Br4–Br6, US Level III–IV, ESAPI/XSAPI). Client mod + closed-source server part. Written in Enforce Script.

## Возможности

- **STOP / CRACK / PEN.** При попадании в грудь или спину с целой плитой исход определяется оставшимся HP плиты:
  - **STOP** и **CRACK** — ванильное попадание отменяется, вместо него мод применяет шок (тупой удар), сниженный защитой плиты, жилета и одежды; при CRACK удар сильнее;
  - **PEN** — урон снижается и идёт дальше в обычную обработку, включая `OMD_NewDamage`.
- **Износ плит.** Плиты теряют ресурс от попаданий.
- **Мягкая защита жилета.** Если плиты нет или её HP равно 0, используется класс мягкой зоны жилета.
- **Ближний бой и заражённые** — ванильная защита жилета; на закрытых зонах броня блокирует царапины заражённых (через `OMD_Bridge`).
- **Бронеплиты:** 10 плит — российские по ГОСТ (сталь Бр4, керамика Бр4/Бр5, композит Бр5, сталь Бр6) и американские (сталь Level III, керамика Level III+ и Level IV, ESAPI, XSAPI). Слоты для передней и задней плиты с отдельными иконками; плиты ставятся в `PlateCarrierVest`.
- **Обратная связь без цифр на HUD:** звук попадания в плиту и искры.

## Roadmap

- Шлемы (запланировано).
- Тестирование пробития (PEN).

## Требования

- DayZ (клиент и сервер)
- [OMD Bridge](https://github.com/Bambuchasensei/OMD_Bridge)
- [OMD NewDamage](https://github.com/Bambuchasensei/OMD_NewDamage)
- Terje: `TerjeMedicine`

## Архитектура

Мод состоит из двух частей:

- **клиентская часть** (этот репозиторий) — подключается через `-mod=` на клиенте и сервере;
- **серверная часть** `OMD_Armor_Server` — подключается на сервере через `-serverMod=`. Исходники серверной части закрыты.

Серверная часть обязательна: без неё мод работает некорректно.

## Установка

1. Подпишитесь на зависимости и на этот мод.
2. Добавьте `OMD_Armor` в `-mod=` клиента и сервера после `OMD_Bridge` и `OMD_NewDamage`.
3. Добавьте `OMD_Armor_Server` в `-serverMod=` сервера.

## Конфигурация

Параметры баланса и список жилетов (кроме `PlateCarrierVest`) задаются в файле `omd/OMD_Armor.json` в папке профиля сервера. Дизайн-заметки — в [docs/design_armor.md](docs/design_armor.md).

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

## Авторы

- **Comrad-Sensei** ([Bambuchasensei](https://github.com/Bambuchasensei))
- **mmetrjuk**

Сообщество и сервер **One More DayZ (OMD)**.

Thanks to Inedia and Terje.

## Лицензия

All rights reserved. Код и ассеты опубликованы для ознакомления (портфолио). Использование, копирование и перезалив — только с разрешения авторов.