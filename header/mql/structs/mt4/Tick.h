#pragma once

/**
 * MT4 struct TICK (Dateiformat "ticks.raw")
 */
struct TICK {                                      // -- offset ---- size --- description ----------------------------------------------------------------------------
   char   symbol[MAX_SYMBOL_LENGTH+1];             //         0        12     Symbol (szchar)
   uint   time;                                    //        12         4     Timestamp
   double bid;                                     //        16         8     Bid
   double ask;                                     //        24         8     Ask
   uint   counter;                                 //        32         4     fortlaufender Z�hler innerhalb der Datei
   BYTE   unknown[4];                              //        36         4     ?
};                                                 // ----------------------------------------------------------------------------------------------------------------
                                                   //                = 40