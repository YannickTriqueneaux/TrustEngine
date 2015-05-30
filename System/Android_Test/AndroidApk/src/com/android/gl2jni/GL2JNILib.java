/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.gl2jni;

// Wrapper for native library

import android.util.Log;

public class GL2JNILib {
     public static final String APP_NAME = "SystemTest";
     static {
         Log.w(APP_NAME,"    ");
         Log.w(APP_NAME, "---------- # " + APP_NAME + " # NEW INSTANCE -------");
         try{
            System.loadLibrary(APP_NAME);
         }catch(Exception e){
            Log.w(APP_NAME, "Error during " + APP_NAME + "'s libraries loading");
         }
         Log.w(APP_NAME, "---------- # End loading " + APP_NAME + " libraries ----------");
     }

    /**
     * @param width the current view width
     * @param height the current view height
     */
     public static native void init(int width, int height);
     //public static native void step(); does not used by tests
}
