
## Método de Geração: Ordenado de forma ascendente
| Tamanho do Array (n) | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort (Original) | Merge Sort | Quick Sort (Pivot no final) |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 128 | 22976.89ns | 333.40ns | 11864.50ns | 6026.00ns | 1879.67ns | 4148.11ns | 20078.25ns |
| 256 | 97333.25ns | 1505.25ns | 123934.57ns | 21687.50ns | 4303.57ns | 8842.56ns | 74937.50ns |
| 512 | 402514.22ns | 1250.00ns | 214760.38ns | 35613.29ns | 9754.78ns | 69005.38ns | 298333.22ns |
| 1024 | 1501750.00ns | 2333.43ns | 678615.78ns | 82857.29ns | 22152.89ns | 144375.00ns | 1102379.89ns |
| 2048 | 5413991.00ns | 4593.62ns | 2694240.89ns | 189018.67ns | 45213.62ns | 83281.25ns | 4427739.62ns |
| 4096 | 21793138.83ns | 8963.50ns | 11331562.67ns | 398109.38ns | 113124.88ns | 1988340.33ns | 17786222.00ns |
| 8192 | 85201073.12ns | 18129.88ns | 42669645.75ns | 816990.67ns | 233276.12ns | 379602.11ns | 70688847.11ns |
| 16384 | 351593273.00ns | 37059.43ns | 184053055.56ns | 1726734.50ns | 481250.12ns | 822486.11ns | 292765035.71ns |
| 32768 | 1398451629.67ns | 74145.75ns | 709314078.25ns | 3587245.22ns | 1037393.67ns | 1680444.67ns | 1159260462.89ns |
| 65536 | 5741072231.56ns | 151759.22ns | 2861046880.86ns | 7460421.22ns | 2219680.44ns | 3509398.33ns | 4870170546.88ns |
## Método de Geração: Ordenado de forma descendente
| Tamanho do Array (n) | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort (Original) | Merge Sort | Quick Sort (Pivot no final) |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 128 | 33652.78ns | 20906.25ns | 14328.25ns | 5333.43ns | 3184.71ns | 4027.78ns | 16755.00ns |
| 256 | 125517.57ns | 308476.14ns | 137437.17ns | 41314.56ns | 7574.00ns | 20847.00ns | 154974.00ns |
| 512 | 3588694.22ns | 365552.12ns | 206364.50ns | 40541.78ns | 16226.00ns | 19398.11ns | 744645.50ns |
| 1024 | 1947754.67ns | 1292453.25ns | 779401.12ns | 74474.12ns | 35146.00ns | 106271.00ns | 986421.75ns |
| 2048 | 7484037.22ns | 5085338.00ns | 3112523.00ns | 214148.33ns | 99809.43ns | 87481.56ns | 3653513.78ns |
| 4096 | 29808499.89ns | 20323643.00ns | 12433509.22ns | 1422472.44ns | 350546.33ns | 387967.44ns | 14610213.38ns |
| 8192 | 120058714.43ns | 81167365.78ns | 49716534.83ns | 830425.78ns | 376675.89ns | 384380.25ns | 58654060.33ns |
| 16384 | 469426421.44ns | 325150421.33ns | 198846547.57ns | 1736972.33ns | 772967.56ns | 816754.78ns | 228071656.25ns |
| 32768 | 1899120717.67ns | 1326020361.22ns | 795419432.12ns | 3626097.22ns | 1709541.50ns | 1657115.78ns | 929765958.33ns |
| 65536 | 7907863229.50ns | 5298185421.44ns | 3162277135.38ns | 7450842.44ns | 3574916.56ns | 3535143.44ns | 3785599239.50ns |
## Método de Geração: Aleatório sem repetição
| Tamanho do Array (n) | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort (Original) | Merge Sort | Quick Sort (Pivot no final) |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 128 | 37573.89ns | 11708.33ns | 16723.88ns | 9500.12ns | 15416.83ns | 22504.78ns | 12999.89ns |
| 256 | 1613000.00ns | 152565.57ns | 120032.33ns | 22173.50ns | 19863.14ns | 18677.25ns | 20101.29ns |
| 512 | 525809.43ns | 172611.11ns | 218333.38ns | 48238.14ns | 58588.50ns | 39636.86ns | 42560.11ns |
| 1024 | 1870727.00ns | 656786.38ns | 1480824.00ns | 153717.56ns | 124500.12ns | 89856.33ns | 61178.29ns |
| 2048 | 7477888.78ns | 2526268.56ns | 2859115.67ns | 226675.89ns | 288477.00ns | 183999.88ns | 137134.11ns |
| 4096 | 31626479.33ns | 10617619.88ns | 11306526.25ns | 493968.75ns | 692393.78ns | 404458.14ns | 297041.78ns |
| 8192 | 145682571.43ns | 41159426.00ns | 44877592.44ns | 1239120.44ns | 1730111.22ns | 860841.60ns | 610071.57ns |
| 16384 | 644022194.44ns | 163343354.12ns | 179593319.44ns | 2334231.22ns | 4111833.50ns | 1914421.88ns | 1352470.43ns |
| 32768 | 2756342988.00ns | 654603851.14ns | 713372437.33ns | 4878062.50ns | 10548972.17ns | 3924310.22ns | 2813375.25ns |
| 65536 | 11434667562.38ns | 2600224939.89ns | 2805661384.11ns | 10524708.22ns | 25282490.67ns | 8258851.29ns | 5880101.00ns |
## Método de Geração: Aleatório com repetição
| Tamanho do Array (n) | Bubble Sort | Insertion Sort | Selection Sort | Heap Sort | Shell Sort (Original) | Merge Sort | Quick Sort (Pivot no final) |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 128 | 35426.00ns | 11137.14ns | 16446.29ns | 22505.86ns | 21282.44ns | 8435.22ns | 11619.29ns |
| 256 | 303658.20ns | 44611.22ns | 144208.50ns | 51111.00ns | 54389.11ns | 19018.67ns | 12775.88ns |
| 512 | 1271364.38ns | 467815.57ns | 410533.60ns | 114606.67ns | 105541.67ns | 88777.83ns | 61994.62ns |
| 1024 | 4083023.00ns | 856822.88ns | 780906.50ns | 208333.44ns | 558874.71ns | 149812.50ns | 129678.71ns |
| 2048 | 7349356.56ns | 2556421.22ns | 2814671.22ns | 238443.00ns | 465895.75ns | 218921.11ns | 238520.67ns |
| 4096 | 31285212.78ns | 10084685.11ns | 11019180.44ns | 525196.43ns | 725281.38ns | 446785.71ns | 333390.50ns |
| 8192 | 144081782.67ns | 40426264.17ns | 44101161.25ns | 1184989.62ns | 1635927.25ns | 852968.50ns | 1914240.56ns |
| 16384 | 646831514.00ns | 159313859.25ns | 176203102.11ns | 2269972.11ns | 4126879.44ns | 1860254.78ns | 1283338.62ns |
| 32768 | 2722415837.89ns | 647271060.33ns | 702652754.67ns | 4900087.78ns | 11010361.11ns | 3919407.56ns | 2797407.44ns |
| 65536 | 11441723226.14ns | 2580861937.38ns | 2801517734.50ns | 10337370.56ns | 26018796.44ns | 8185916.67ns | 5911398.11ns |