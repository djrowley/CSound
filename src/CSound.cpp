/* 
    This library is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

//#include <avr/interrupt.h>
//#include <avr/pgmspace.h>
//#include <Arduino.h>
//#include <pins_arduino.h>
#include "CSound.h"

#define SOUND_RX_PIN 10
#define SOUND_TX_PIN 11

SoftwareSerial dfSerial(SOUND_RX_PIN, SOUND_TX_PIN);


bool CSound::begin()
{
    // set up audio
    dfSerial.begin(9600);

    if(!dfPlayer.begin(dfSerial))
    {
      return false;
    }
  
    dfPlayer.setTimeOut(500); //Set serial communication time out 500ms
    dfPlayer.volume(30);  //Set volume value (0~30).
    dfPlayer.outputDevice(DFPLAYER_DEVICE_SD);
	
	return true;
}

void CSound::playStartup()
{
  dfPlayer.playFolder(1,1);
}

void CSound::playFire()
{
  dfPlayer.playFolder(2,1);
}

void CSound::playReload()
{
  dfPlayer.playFolder(3,1);
}

void CSound::playOutOfAmmo()
{
  dfPlayer.playFolder(4,1);
}

