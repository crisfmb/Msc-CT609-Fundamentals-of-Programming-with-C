/* Cristina Borges - MCT Assignment 5 - Question 1

Select two of the sort algorithms we have discussed in class.

1.Code the selected algorithms
2. Instrument your sort algorithms to calculate efficiency by gathering data on:
        a.Time for algorithm to run
        b.Number of swaps
        c.Number of comparisons 
3. Download the Peak Wind speed at 80meter data for your birthday in 2013 from the following website:
http://www.nrel.gov/midc/apps/daily.pl?site=NWTC&start=20010824&yr=2014&mo=7&dy=24
4. Copy and paste the data into a file.
5. Working from this data file, load the last column (wind speeds) of the comma delimited file into a one-dimensional array.
6. Run both of your instrumented algorithms again with the wind speed data you created.
7. Save the sorted data in a new file to be used in Question 2.
8. Display your results and discuss which algorithm performed better on your data set.

        Enter the date of your 2013 birthday as both the starting and ending date.
        Check the box for the “Pk Wind Speed (80m)” in the right-hand column. 
        Select the output type “1-Min data (ASCII text)” in the left-hand column near the bottom
        Click on the Submit button. 

This will generate an ACSII list of the Peak Wind speed at 80meter in Colorado on your birthday in 2013.



 **************** BUBBLE SORT ****************** */

#include <stdio.h> //perform I/O operations. Tells the preprocessor to include the "stdio.h" header file to support input/output operations
#include <time.h>  /* This header file contains definitions of functions to get and manipulate date and time information. */

#define SIZE 1440 // define SIZE constant for us in array length

int main()
{
    double array[SIZE] = {6.4885, 5.4616, 5.8767, 5.7019, 5.6364, 6.0078, 6.0297, 5.7675, 5.9641, 6.3793, 5.549, 5.549, 4.959, 4.7842, 4.8935, 5.1338, 4.959, 5.0464, 5.2212, 5.396, 5.3305, 4.8279, 5.549, 6.0734, 6.9474, 6.0515, 5.7893, 6.0515, 6.86, 6.8381, 5.986, 6.27, 6.0734, 6.0952, 6.0297, 6.4011, 6.3356, 6.5541, 6.9692, 6.1171, 6.9037, 6.7944, 6.2482, 6.27, 6.27, 5.8549, 5.7456, 5.7456, 5.7893, 5.112, 5.4397, 5.2212, 5.5708, 5.7238, 4.9809, 4.1724, 5.1994, 4.7187, 4.9153, 4.6968, 4.4783, 4.4346, 4.3909, 5.0246, 5.2431, 4.9153, 4.675, 4.8061, 5.2212, 5.0464, 4.8498, 5.2212, 5.7675, 6.0297, 5.986, 6.5759, 5.549, 6.1389, 5.3305, 5.2868, 5.112, 6.0297, 5.7675, 5.9204, 5.0246, 5.9204, 6.1171, 5.3523, 5.7675, 5.7456, 6.2919, 6.6196, 6.6852, 6.0515, 6.5322, 6.5541, 6.1826, 5.4616, 5.0901, 5.549, 5.5927, 5.4834, 6.2045, 6.0297, 5.7238, 5.8767, 5.3086, 5.7238, 5.3523, 5.9204, 6.0734, 5.8986, 5.9641, 5.8767, 6.4448, 6.3137, 5.833, 6.0297, 5.9641, 5.8112, 6.0515, 6.1608, 5.7456, 5.5927, 6.0297, 5.7238, 5.6801, 5.0901, 5.3305, 5.3305, 5.9204, 5.3086, 5.7019, 5.5708, 5.3523, 5.4397, 5.4179, 5.5271, 5.6801, 5.8767, 5.9641, 5.8767, 6.0078, 6.27, 6.0734, 6.2482, 5.7675, 5.7238, 6.1171, 5.3305, 5.6364, 5.4616, 5.7456, 6.0078, 6.5104, 5.9423, 5.3086, 5.8986, 5.8112, 6.4448, 6.0734, 6.1389, 5.5053, 5.6145, 5.5927, 6.1171, 5.986, 5.8549, 5.5708, 5.2868, 5.4834, 5.1338, 5.4616, 5.1557, 5.3523, 5.4397, 5.3305, 5.7456, 5.5708, 5.6364, 5.7019, 5.5053, 5.2212, 5.112, 5.2431, 5.4834, 4.959, 5.8549, 5.9204, 5.3523, 5.8986, 7.2533, 6.707, 5.6145, 5.6582, 5.3742, 5.7238, 5.4616, 6.3356, 6.7944, 6.5104, 8.4113, 7.4718, 6.7726, 8.9576, 9.1542, 8.5206, 8.9576, 8.4987, 9.1324, 8.0617, 8.3021, 7.3188, 8.3021, 7.3407, 7.8651, 7.8869, 7.9962, 6.9255, 7.5592, 7.734, 7.7777, 8.1273, 8.6298, 9.0013, 9.4601, 9.6786, 10.225, 9.8753, 10.618, 10.181, 9.9845, 10.094, 8.9139, 9.3072, 9.2853, 9.766, 10.072, 10.356, 10.946, 10.094, 9.5912, 9.6349, 9.0231, 8.2147, 8.7172, 9.0668, 9.0231, 9.8971, 9.7442, 9.2198, 10.094, 10.159, 9.4383, 9.2853, 9.4164, 10.727, 11.099, 11.186, 11.623, 11.405, 10.29, 10.05, 11.121, 10.574, 10.553, 10.596, 11.296, 12.17, 12.235, 11.995, 11.47, 10.902, 10.706, 10.837, 10.859, 11.317, 11.317, 11.82, 11.448, 11.252, 11.995, 11.601, 11.842, 11.58, 10.64, 11.58, 11.186, 10.028, 10.334, 10.094, 10.946, 10.618, 9.2198, 10.05, 9.2198, 10.159, 9.1979, 8.892, 9.5912, 9.045, 8.8702, 8.8483, 8.3676, 8.1928, 8.1491, 9.3946, 9.4164, 8.5206, 8.1928, 8.1273, 8.6735, 8.1273, 8.7828, 8.4332, 8.1273, 7.8214, 7.4718, 7.0566, 7.7121, 8.0836, 8.0617, 7.297, 8.1054, 7.7995, 7.4718, 7.1659, 7.4062, 6.8818, 7.4718, 6.86, 6.86, 7.3625, 6.9474, 7.0566, 7.0348, 6.5759, 6.3793, 7.4499, 7.3844, 7.0348, 7.4936, 7.1877, 6.6852, 7.144, 7.0129, 7.5155, 7.0566, 6.4667, 5.9641, 6.6852, 6.7289, 6.2045, 6.8818, 6.6633, 6.2263, 6.0734, 5.7893, 5.9423, 5.9641, 6.6196, 6.4448, 6.6196, 6.3574, 5.7456, 5.7893, 5.6145, 5.9641, 6.0952, 5.5053, 5.4616, 5.4397, 6.0734, 5.7456, 5.8767, 5.6582, 5.5053, 5.396, 5.396, 4.8935, 4.9153, 5.2868, 4.7624, 5.3742, 5.3523, 5.2212, 5.549, 5.8112, 5.9204, 6.1389, 6.7944, 6.423, 6.3137, 6.4885, 6.4448, 6.3137, 6.707, 6.6852, 6.7289, 6.707, 6.5104, 6.5541, 6.707, 6.8163, 6.6852, 7.6466, 7.2314, 7.1222, 6.9474, 6.7507, 7.0129, 7.2533, 6.5978, 6.3137, 6.7726, 6.5759, 6.7726, 6.6415, 5.9423, 6.2482, 6.3137, 6.0734, 5.9204, 5.986, 6.2045, 6.2482, 6.2919, 6.3574, 5.833, 5.8549, 5.6582, 5.6145, 5.3742, 5.6801, 5.5053, 5.8112, 5.8986, 5.7893, 5.5271, 6.0297, 5.6145, 5.7456, 5.549, 5.7456, 6.0734, 5.4616, 5.6582, 5.2431, 5.1994, 5.0683, 5.2212, 5.0027, 4.8716, 5.0027, 5.0464, 5.0464, 4.8061, 4.5657, 4.4783, 4.675, 4.6313, 4.5002, 4.522, 4.522, 4.3691, 4.3472, 4.5657, 4.2817, 4.6968, 4.3691, 3.6917, 4.0195, 4.3691, 4.6531, 4.3909, 4.4346, 3.9321, 3.8884, 3.9321, 4.1287, 4.238, 4.3472, 4.4128, 4.3691, 4.2598, 4.0195, 4.5002, 4.3909, 4.4565, 4.6531, 4.7405, 4.1287, 4.0413, 4.0632, 4.085, 4.1506, 3.8884, 4.0413, 3.6262, 3.5606, 3.5388, 3.4514, 3.4295, 3.364, 3.3421, 3.4732, 3.1455, 2.8614, 2.5337, 2.5337, 2.4681, 2.8614, 2.8833, 2.7303, 2.4463, 3.0581, 2.9925, 2.8177, 3.0799, 3.1018, 2.6429, 2.5118, 2.4463, 2.7303, 2.3807, 2.5337, 2.5774, 2.927, 2.7959, 2.5992, 2.49, 2.2715, 2.3589, 2.5992, 3.0362, 2.5992, 2.7303, 2.5992, 3.0144, 3.1018, 3.1892, 2.7085, 2.5118, 2.5555, 2.5118, 2.8833, 2.6211, 3.1673, 3.2547, 3.4951, 2.5555, 2.5774, 2.7085, 2.927, 2.6211, 2.2715, 2.5118, 2.8833, 2.7959, 2.774, 2.5118, 2.6211, 2.774, 2.9707, 2.7522, 3.2766, 3.0581, 2.5118, 2.4681, 3.1673, 2.8396, 2.6866, 2.6648, 2.7959, 2.8177, 2.8614, 2.4681, 1.9437, 1.8345, 2.2278, 2.5337, 2.5555, 3.0144, 3.0581, 3.1455, 2.9488, 3.1236, 3.0362, 2.9051, 2.2933, 2.4244, 2.2715, 2.7959, 2.8177, 2.9051, 3.0144, 2.9051, 2.8833, 2.5555, 2.5337, 2.337, 2.7303, 2.6648, 2.5337, 2.5555, 2.8177, 3.1236, 2.8396, 2.9488, 3.2329, 3.2766, 3.0144, 2.7303, 3.3203, 3.1455, 3.1892, 3.6262, 3.6262, 3.4514, 3.6262, 4.1943, 3.3203, 3.4077, 3.4295, 3.7136, 3.9539, 3.5606, 3.4514, 3.1892, 3.0581, 3.0799, 4.3909, 3.1455, 2.9488, 3.7573, 3.0799, 3.1018, 2.5774, 2.5555, 2.9707, 3.211, 2.774, 2.6866, 2.9925, 2.8614, 2.4026, 2.2715, 3.6043, 2.774, 2.9488, 2.5992, 2.8614, 2.927, 2.6211, 3.364, 3.1673, 3.2329, 3.4077, 3.0144, 3.2547, 3.4295, 3.4951, 3.801, 3.4077, 3.5825, 3.6043, 3.3203, 3.3858, 3.0799, 3.8884, 3.5825, 3.7573, 3.9102, 3.9758, 3.9976, 4.1943, 3.7354, 3.4514, 3.5169, 3.2766, 3.8884, 4.238, 4.5657, 4.1069, 3.364, 4.1724, 4.0195, 3.6699, 4.085, 3.9539, 4.0632, 3.6043, 3.5169, 3.9102, 4.0632, 3.9321, 3.5606, 3.9539, 3.364, 3.2329, 4.0195, 3.801, 4.1069, 4.1506, 3.7573, 3.5825, 3.5606, 3.5169, 3.3203, 3.1892, 3.6917, 3.801, 3.7791, 4.1724, 3.9321, 3.2329, 3.1018, 3.4514, 3.801, 3.8665, 4.0413, 3.7136, 3.4951, 3.2766, 3.8228, 3.6917, 3.801, 4.1287, 3.9102, 3.9321, 3.5388, 3.4077, 3.801, 3.7791, 3.9321, 3.211, 3.8228, 4.0632, 3.9976, 4.0195, 4.085, 3.9321, 3.8665, 3.648, 3.2984, 3.4951, 3.2766, 3.9758, 4.238, 4.4346, 4.5657, 4.5876, 4.522, 4.0195, 4.1724, 4.1724, 4.3909, 4.2598, 4.5657, 4.8498, 4.085, 4.3035, 4.1506, 4.1724, 4.0195, 4.1069, 3.2766, 3.0799, 2.7303, 3.0144, 3.1892, 3.2329, 2.4026, 3.1892, 3.7136, 3.3203, 3.6043, 3.0581, 4.1506, 4.085, 4.4565, 4.4128, 5.1338, 4.8716, 5.0464, 4.6094, 5.0901, 5.0901, 4.6968, 4.3254, 4.2817, 3.9539, 3.7354, 3.9539, 4.522, 4.0632, 4.3472, 4.1506, 3.9539, 3.8228, 3.1673, 3.0362, 3.1455, 2.9707, 3.6043, 3.6917, 3.1018, 2.927, 3.3421, 3.5169, 3.2329, 3.1018, 3.2547, 3.5606, 3.7354, 3.6917, 3.8228, 3.8884, 4.0413, 3.8447, 3.6699, 3.4077, 2.5555, 3.0144, 3.6917, 3.7136, 4.0632, 4.6968, 3.648, 4.1069, 4.8716, 4.4565, 4.5002, 4.2817, 4.2598, 4.2598, 4.1069, 4.3472, 4.2817, 3.4077, 3.5388, 3.4732, 3.5388, 3.8228, 3.8228, 3.8884, 3.8447, 3.4077, 4.0195, 3.8447, 3.5169, 4.1724, 3.8665, 3.6262, 3.9976, 4.1069, 4.5876, 4.3254, 3.9539, 3.801, 3.7791, 3.9321, 3.5606, 3.801, 3.5388, 3.2547, 3.364, 3.4732, 3.7354, 3.2984, 3.4514, 3.364, 3.7791, 3.8228, 3.2329, 3.5606, 3.5606, 3.6262, 3.4514, 3.3858, 3.211, 3.4295, 2.9925, 2.5774, 2.4681, 2.2278, 2.3589, 2.8396, 2.7303, 1.5723, 1.7689, 1.7252, 1.5941, 2.1841, 2.3589, 2.1622, 2.2715, 2.5555, 2.6866, 2.6866, 2.337, 2.1622, 2.6648, 2.7522, 3.2329, 3.2984, 2.9925, 3.364, 3.1673, 3.364, 3.4514, 3.6262, 3.4514, 3.6699, 3.7136, 4.1069, 3.2547, 2.6211, 2.2933, 2.5118, 2.3807, 2.774, 2.8614, 2.8396, 2.9707, 3.7136, 3.211, 2.7522, 2.6211, 3.2329, 2.9707, 3.2766, 2.8614, 2.6429, 2.9488, 2.8614, 2.774, 2.774, 2.5992, 2.5774, 2.2278, 1.9219, 2.337, 2.6429, 2.7303, 2.8396, 3.0581, 2.6429, 2.6211, 3.5388, 3.5388, 3.5606, 3.648, 3.9102, 3.3858, 3.1236, 3.2766, 3.0144, 2.8396, 3.0362, 3.0144, 2.7522, 3.0362, 2.7959, 2.49, 2.6211, 2.9051, 2.7522, 2.5337, 2.7303, 2.927, 2.9051, 3.0362, 2.8177, 3.1673, 3.364, 3.1018, 2.774, 2.6866, 2.1622, 2.1841, 2.7522, 2.9488, 2.774, 2.5118, 3.0581, 2.8614, 2.8177, 2.49, 2.337, 2.6211, 2.7959, 2.8396, 2.6866, 2.7959, 2.8833, 2.7959, 2.927, 2.5118, 2.4681, 2.337, 2.2059, 2.5774, 2.5118, 2.6429, 2.5774, 2.3152, 2.4463, 2.0967, 2.1622, 2.2715, 2.3807, 2.1841, 2.053, 2.2059, 2.2059, 2.0967, 1.7034, 1.9, 1.7689, 1.8345, 2.4026, 2.5992, 2.2278, 2.1841, 1.7034, 1.9437, 2.1185, 2.0748, 2.4463, 2.7959, 2.7959, 2.3589, 2.053, 2.49, 2.2278, 2.3589, 2.2278, 2.3807, 2.7085, 2.6866, 2.774, 2.8396, 2.774, 2.6429, 2.5774, 2.5774, 2.0748, 1.9656, 2.0748, 2.3152, 2.053, 2.0093, 2.5118, 2.6429, 2.49, 2.4681, 2.9051, 2.3152, 2.2496, 2.2933, 1.9, 2.2059, 2.8833, 2.927, 3.1892, 2.0093, 2.2715, 2.6429, 1.9, 2.3807, 2.7303, 2.7959, 2.1185, 2.3807, 2.49, 1.9874, 1.9874, 2.4463, 2.4026, 2.2715, 2.1404, 2.3589, 2.1622, 2.1622, 2.5118, 2.5555, 2.6211, 2.5774, 2.4681, 2.4681, 2.7085, 3.1018, 2.6866, 2.9707, 2.9488, 2.8177, 2.6866, 2.4463, 3.2329, 2.7522, 3.1236, 3.1236, 2.927, 2.774, 2.9488, 2.7959, 3.1892, 3.5825, 3.1673, 2.8614, 2.1841, 2.0748, 2.3589, 2.4244, 2.4026, 2.337, 2.6648, 2.5118, 2.4463, 2.9925, 2.49, 2.1404, 1.4412, 1.616, 1.8126, 2.2933, 2.6866, 2.6866, 2.9707, 2.5337, 2.2496, 2.1622, 2.4681, 2.8177, 2.6648, 2.4681, 2.774, 2.5774, 1.7689, 1.7689, 1.7471, 1.6378, 2.2933, 2.053, 2.0748, 2.5774, 2.4463, 2.6866, 1.6597, 1.8126, 1.7908, 1.9437, 1.8126, 1.7252, 1.6378, 1.5504, 1.3975, 2.0967, 1.5286, 1.3538, 1.5067, 1.9874, 1.9, 1.8126, 1.5504, 1.7689, 1.6815, 1.3975, 1.6815, 2.0093, 2.0748, 2.2496, 2.3807, 1.6815, 1.5067, 1.2008, 1.7034, 1.7471, 1.6815, 1.463, 1.9656, 2.0311, 1.9874, 0.9168, 2.2933, 2.2496, 1.7471, 2.0093, 1.7034, 1.9219, 2.3152, 2.2496, 1.8345, 1.5941, 1.8563, 1.9, 2.0311, 2.4463, 2.0311, 1.9656, 1.8782, 2.6648, 1.9656, 2.9051, 2.7522, 2.1185, 1.9874, 1.9, 2.1404, 3.2766, 2.8614, 2.1185, 1.7252, 1.7471, 2.0967, 2.3807, 1.5286, 2.5555, 2.4244, 1.616, 1.8563, 1.463, 1.8563, 2.0093, 2.3152, 1.9437, 2.2933, 2.053, 2.1404, 2.0311, 1.7689, 1.9219, 1.616, 1.7908, 1.5286, 1.5941, 1.2008, 1.9656, 2.1841, 2.337, 1.5723, 1.9656, 1.8782, 1.8563, 1.7034, 1.8345, 2.053, 2.2496, 1.7034, 1.8345, 1.2882, 1.9874, 2.2059, 1.7908, 1.7471, 1.9, 1.9874, 2.2059, 2.1622, 2.0967, 1.5286, 1.9219, 1.5941, 2.1622, 2.2059, 1.8782, 1.5504, 1.6378, 1.3975, 1.6815, 1.7034, 1.9437, 1.7908, 1.4849, 1.5504, 1.7252, 1.4412, 2.0967, 2.0093, 2.0748, 1.7689, 1.8563, 1.7689, 1.6378, 1.2882, 2.0311, 2.337, 2.7085, 2.6648, 2.7085, 2.1404, 2.1622, 2.3807, 3.0362, 2.2933, 2.2933, 2.5118, 3.1018, 2.7303, 2.927, 2.7303, 2.7085, 2.3152, 2.5555, 2.49, 2.0093, 2.3589, 1.9437, 2.0311, 1.8345, 1.9219, 1.5723, 1.5067, 1.8126, 2.1185, 2.1404, 2.053, 2.1185, 1.9437, 1.9, 1.7252, 2.2715, 1.9219, 1.7034, 1.7908, 1.9219, 2.053, 2.2278, 1.9219, 1.7908, 1.9874, 2.2933, 2.0967, 2.053, 2.3589, 1.616, 1.6815, 1.8563, 2.053, 2.2496, 2.5555, 1.9874, 1.3538, 2.0748, 2.0748, 2.1841, 1.7908, 2.0748, 1.9656, 1.7908, 1.9219, 1.9656, 1.8782, 2.053, 2.49, 2.3589, 1.5504, 1.3975, 1.2008, 1.7252, 1.6815, 1.5286, 1.9437, 1.7252, 1.9437, 1.6597, 2.0967, 1.7034, 1.9437, 2.3152, 1.8345, 1.9874, 1.5504, 1.5723, 1.5941, 1.8345, 1.9219, 1.9656, 1.8126, 1.9, 1.7908, 2.0093, 1.9219, 1.7252, 1.5067, 1.6378, 1.6597, 1.8345, 2.0967, 2.0967, 2.053, 2.4244, 2.3589, 1.9, 1.4412, 1.5286, 1.7471, 1.616, 1.3101, 1.5286, 1.6378, 1.4849, 1.3101, 1.3756, 1.026, 1.6378, 1.4849, 1.2882, 1.2882, 1.7471, 1.8126, 1.6597, 1.3538, 1.6597, 1.5286, 1.1571, 1.2227, 1.3319, 2.1841, 1.463, 1.7034, 1.7689, 1.7689, 1.4849, 1.5067, 1.3319, 1.616, 1.6378, 1.5723, 1.5504, 1.3975, 1.5723, 1.616, 1.7689, 1.4193, 1.4193, 1.4412, 1.4193, 1.616};
    int comparisons = 0; // declare and initialize comparisons counter
    int swaps = 0;       // declare and initialize swaps counter
    double temp;         // declare temp variable for storing array element in event of swap
    clock_t startTime;   // declare starTime variable for measuring execution time
    clock_t endTime;     // declare endTime variable for measuring execution time
    double totalTime;    // declare totalTime for measuring execution time
    int i;               // declare counter for comparisons
    int j;               // declare counter for passes

    startTime = clock(); // set start time

    // iterate through entire array SIZE - 1 passes and compare each i element to each i + 1 element to determine swaps

    for (j = 0; j < SIZE; j++)
    {
        for (i = 0; i < (SIZE - 1); i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];         // store array element in temp
                array[i] = array[i + 1]; // swap elements
                array[i + 1] = temp;     // set array element to temp value
                swaps++;                 // increment swaps by 1
            }
            comparisons++; // increment comparisons by 1
        }
    }

    endTime = clock(); // set end time

    totalTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC; // calculate total time to execute

    // print array results

    for (i = 0; i < SIZE; i++)
    {
        if (i == 0)
        {
            printf("{%1.4f, ", array[i]); // formatting for first array element
        }
        else if (i == SIZE - 1)
        {
            printf("%1.4f}\n", array[i]); // formatting for last array element
        }
        else
        {
            printf("%1.4f, ", array[i]); // formatting for all other array elements
        }
    }

    // print performance results

    printf("\nThe total number of swaps is: %d", swaps);
    printf("\nThe total number of comparisons is: %d", comparisons);
    printf("\nThe total time to execute is: %f seconds\n", totalTime);

    return 0;
}