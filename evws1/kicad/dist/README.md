# Manufacturing report

## Gerber Files

See [https://support.jlcpcb.com/article/44-how-to-export-kicad-pcb-to-gerber-files](https://support.jlcpcb.com/article/44-how-to-export-kicad-pcb-to-gerber-files)

## Manufacturing details

* Tapeout: 23.2.2020
  [https://jlcpcb.com/client/index.html#/order](https://jlcpcb.com/client/index.html#/order)
  Order Number: Y11-2360571A (5 pcs, €62,95 EUR)
 

## Bugs / Improvements

Mechanical Drawings from Layer NP to PHT(PLATING Through Hole) (email request from support@jlcpcb.com on 2018-09-21)

| Reference      | Description                                                |
| -------------- | ---------------------------------------------------------- |
| U1             | increase gap between pads                                  |
| SW5            | flip 1 / 3, LCD backlight is on if switch button down      |
| C47, C48       | do not assemble                                            |
| R49            | 1K8 instead of 10K                                         |
| R27, R28       | use 8K2? instead of 10K                                    |
| R50            | 1K2 instead of 10K                                         |
| R10, R11       | 2K2 instead of 820R                                        |
| U13            | reduce pads gap between rows                               |
| RV3, R85, R86  | Offset trimming 60mV too low, use RV3=5K, R85=15K, R86=2K7 |
| RV5, R87, R88  | Offset trimming 60mV too low, use RV5=5K, R87=15K, R88=2K7 |

## Board placement 

| Board | Reference      | Description                                                |
| ----- | -------------- | ---------------------------------------------------------- |
|    #1 | RV3, R86       | V1 Offset trimming 60mV, use RV3=1K, R86=4K7               |
|    #1 | RV5, R88       | V2 Offset trimming 60mV, use RV5=1K, R86=2K7               |
|    #1 | R10, R11       | 1K5 instead of 2K2                                         |
|    #2 | RV2, R81       | V1 Gain trimming, RV2=500R, R81=680R                       |
|    #2 | RV4, R82       | V2 Gain trimming, RV4=500R, R82=680R                       |




