//Program for sorting

int l;

void setup() 
{
  int i=0;
  vm[4]=0;
  vr[4]=0;
}

void loop() 
{
  //Empty the main stack...
  
  gotomainstack(0);
  vm[i]=identify();       //identify colour and assign colour to blocks from 1 to 4.. later will change it to 3..
  i++;
  if(vm[3]==1)
  { 
    donotpickup();      // do nothing...
  }
  else
    pickup(no):         // pickup the block...
  
  if(i==1)
  { gotostack(2);
    putdown();          //put down the block
                        /*  the pick and put programs would rotate the motor for 0.5seconds 
                            in clockwise and anticlockwise direction for lifting the fork attached to motor
                          */      
    vr[i-1]=vm[i-1];
    vm[i-1]=0;
  }
  if(vm[0]==1)
  {
    gotostack(2);
    putdown();
    vl[i-1]=vm[i-1];
    vm[i-1]=0;
  }
  else if(vl[i-1]>vm[i-1])
  {
    gotostack(2);  
    putdown();
    vr[i-1]=vm[i-1];
    vm[i-1]=0;
  }
  
  else if(vl[0]==0)
  {
    gotostack(1);  
    putdown();
    vl[i-1]=vm[i-1];
    vm[i-1]=0;
  }
  else if(vl[i-1]>vm[i-1])
  {
    gotostack(1);  
    putdown();
    vl[i-1]=vm[i-1];
    vm[i-1]=0;
  }
  else
  {
    if(abs(vl[i-1]-vm[i-1])>abs(vr[i-1]-vm[i-1]))
    {
      gotostack(2);
      putdown();
      vr[i-1]=vm[i-1]; 
      vm[i-1]=0; 
    }
    else
    {
      gotostack(1);
      putdown();
      vl[i-1]=vm[i-1];
      vm[i-1]=0;
    }
  }
  
  
  //after main stack is empty...
  if(i==4)
  {
    int v,w,no,n,j=1;
    while(j<5)
    {    
      v=searchstack(j); //search which stack has the block
      w=prepos;           // gives the current position of the bot..
      no=whichstno(j);      // return the pos of block in the respective stacks..
      if(v==0)
      {
        j++;
      }
      else
      {
        gotostack(v,w);                    //go to stack
        n=identify();                     //identify colour and box no.
        if(n==j)
        {
          pickup(no);
          if(v==1)
            side=1;
          else
            side=2  
          gotomainstack(side);
          putdown();
          j++;    
        }  
        else
        {
          pickup(no);
          gotootherstack(v);
          putdown();        
          
        }
    
       }
     }
  }  
}





//go to main stack...
void gotomainstack(side)
{ 
  if(side==1)
  {
    turn(180);
    while(linefollow());
    for(l=2;l<=4;l++)
    {
      if(vl[l]==0)
      {
        moveforward();      // give half rotation to wheels so that it move forward without any condition..
        while(linefollow());      // code for line follower..
        
      }
    }
    while(linefollow());
    turn(70);                     // takes argument as angle and turn it .. no need to write its code .. I will do that..
    moveforward();
    for(k=4;k>=2;k--)
    {
      if(vm[k]==0)
      {  moveforward();
         while(linefollow());  
      }
    }
    
  }  

  else if(side==2)
  {
    turn(180);
    while(linefollow());
    for(l=2;l<=4;l++)
    {
      if(vr[l]==0)
      {
        moveforward();
        while(linefollow());
        
      }
    }
    turn(-70);
    moveforward();
    while(linefollow());
    for(k=4;k>=2;k--)
    {
      if(vm[k]==0)
      {  moveforward();
         while(linefollow());  
      }
    }  
    
  }
  else if(side==0)
  {
    moveforward();
    while(linefollow());
    for(k=4;k>=2;k--)
    {
      if(vm[k]==0)
      {  moveforward();
         while(linefollow());  
      }
    }  
  }   
  prepos=0; 
}

//go to side stacks..
void gotostack(st,fst)  //st-> go to that stack    fst-> the present stack..
{
  if(fst==2)
  {
      turn(180);
      while(linefollow());
      for(l=2;l<=4;l++)
      {
        if(vr[l]==0)
        {
          moveforward();
          while(linefollow());
          
        }
      }
      moveforward();
      while(linefollow());
      for(k=4;k>=2;k--)
      {
        if(vl[k]==0)
        {
          moveforward();
          while(linefollow());  
        }
          
      }
      prepos=1;
  }
  else if(fst==1)
  {
      turn(180);
      while(linefollow());
      for(l=2;l<=4;l++)
      {
        if(vl[l]==0)
        {
          moveforward();
          while(linefollow());
          
        }
      }  
      moveforward();
      while(linefollow());
      for(k=4;k>=2;k--)
      {
        if(vr[k]==0)
        {
          moveforward();
          while(linefollow());  
        }
      }
      prepos=2;
  }
  else if(fst==0)
  { 
    if(st==1)
    {
      turn(180);
      while(linefollow());
      for(l=2;l<=4;l++)
      {
        if(vm[l]==0)
        {
          moveforward();
          while(linefollow());
          
        }
      }  
      moveforward();
      while(linefollow());
      for(k=4;k>=2;k--)
      {
        if(vl[k]==0)
        {
          moveforward();
          while(linefollow());  
        }
          
      }
      prepos=1;
    }
    else if(st==2)
    {
      turn(180);
      while(linefollow());
      for(l=2;l<=4;l++)
      {
        if(vm[l]==0)
        {
          moveforward();
          while(linefollow());
          
        }
      }  
      moveforward();
      while(linefollow());
      for(k=4;k>=2;k--)
      {
        if(vr[k]==0)
        {
          moveforward();
          while(linefollow());  
        }
          
      }
      prepos=2;
    }
    
  }
  
}

//go to other stack...

void gotootherstack(str)
{
  if(str==1)
  {
      turn(180);
      while(linefollow());
      for(l=2;l<=4;l++)
      {
        if(vl[l]==0)
        {
          moveforward();
          while(linefollow());
          
        }
      }  
      moveforward();
      while(linefollow());
      for(k=4;k>=2;k--)
      {
        if(vr[k]==0)
        {
          moveforward();
          while(linefollow());  
        }
          
      }
      prepos=2;
  }
  else if(str==2)
  {
    turn(180);
      while(linefollow());
      for(l=2;l<=4;l++)
      {
        if(vr[l]==0)
        {
          moveforward();
          while(linefollow());
          
        }
      }  
      moveforward();
      while(linefollow());
      for(k=4;k>=2;k--)
      {
        if(vl[k]==0)
        {
          moveforward();
          while(linefollow());  
        }
          
      }
      prepos=1;
  }  
}

// search for block in both the stacks....
int searchstack(v)
{
  for(h=1;h<=4;h++)
  {
    if(v==vr[h])
    {
      return 2;
      break;
    }
    else if(v==vl[h])
    {
      return 1;
      break;
    }
    else
    {
      return 0;
      break;
    }
  }
    
}

// return on which division the block is placed....
int whichstno()
{
  for(h=1;h<=4;h++)
  {
    if(v==vr[h])
    {
      return h;
      break;
    }
    else if(v==vl[h])
    {
      return h;
      break;
    }
    else
    {
      return h;
      break;
    }
  }
}


