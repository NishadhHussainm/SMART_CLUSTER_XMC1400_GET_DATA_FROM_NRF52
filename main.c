#include "DAVE.h"
#include"stdio.h"

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();
  if (status == DAVE_STATUS_FAILURE)
  {
    XMC_DEBUG(("DAVE Apps initialization failed with status %d\n", status));
   }

  while (1U)
    {
	  //Infinite loop
    }

  return 1;
}
