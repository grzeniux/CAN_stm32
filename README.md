# Lokalizacja Firmware

Do poprawnego zainstalowania potrzebne jest ustawienie zmiennej środowiskowej `STM32_FW_Emoto`. Jej wartość wskazuje lokalizację firmware wraz z poprawną wersją, co może być znalezione w ustawieniach CubeMX których fragment pokazano poniżej.

![Mcu and firmware package.png](./Mcu%20and%20firmware%20package.png)


```bash
export STM32_FW_Emoto=/home/szymon/STM32Cube/Repository/STM32Cube_FW_L4_V1.18.0
```

Dla linux-a aby zmienna była stała można dodać wpis do `/etc/profile.d`. Dla windows-a zakładka zmienne środowiskowe

```bash
echo 'export STM32_FW_Emoto=/home/szymon/STM32Cube/Repository/STM32Cube_FW_L4_V1.18.0' | sudo tee /etc/profile.d/stm32-fw-emoto.sh
```

## Wymagane pakiety

Powinny się też znajować w zmiennej środowiskowej `$PATH`


- gcc-arm-none-eabi - toolchain dla stm32 arm
- make - narzędzie budowania, CubeMX generuje `makefile` używane przez wspomniane narzędzie
- cmake - automat do budowania (lepsza wersja powyższego). Wspierany przez VSCode oraz CubeIDE (>=1.14)
- ninja-build (opcjonalne) - `cmake` konfiguruje projekt do `make`, ale może też do `ninja`, która jest dużo szybsza w budowaniu całości
- gdb-multiarch - debugger. W nowszych wersjach jest on zamiast `arm-none-eabi-gdb`

W przypadku debugger-a może okazać się konieczna poniższa komenda

```bash
sudo ln -s /usr/bin/gdb-multiarch /usr/bin/arm-none-eabi-gdb
```
