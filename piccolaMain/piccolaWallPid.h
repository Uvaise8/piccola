void leftPid()
{
    leftError = 50 - tof[0];
    //wallLastError = 0 - (leftError * 2);
    correction = (leftError * leftP) + ((leftError - leftLastError) * leftD);
    leftLastError = leftError;
    if (correction > 20 )
    {
        correction = 0;
    }

    else if (correction < -20)
    {
        correction = 0;
    }
    leftPwm = leftBase + correction;
    rightPwm = rightBase - correction;
}

void rightPid()
{
    rightError = 58 - tof[4];
    //wallLastError = rightError * 2;
    correction  = (rightError * rightP) + ((rightError - rightLastError) * rightD);
    rightLastError = rightError;
    if (correction > 20 )
    {
        correction = 0;
    }

    else if (correction < -20)
    {
        correction = 0;
    }
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}

void wallPid()
{
    wallError = tof[0] - (tof[4]-8);
    //rightLastError = 58 - tof[4];
    //leftLastError = 50 - tof[0];
    correction = (wallError * wallP) + ((wallError - wallLastError) * wallD);
    wallLastError = wallError;
    if (correction > 20 )
    {
        correction = 0;
    }

    else if (correction < -20)
    {
        correction = 0;
    }
    leftPwm = leftBase - correction;
    rightPwm = rightBase + correction;

}

void wallFollow()
{
    checkWallsPid();
    if (wallAvailable[0] == 1 && wallAvailable[2] == 1)
    {
        wallPid();
        forward();
    }

    else if (wallAvailable[0] == 0 && wallAvailable[2] == 1)
    {
        rightPid();
        forward();
    }

    else if (wallAvailable[0] == 1 && wallAvailable[2] == 0)
    {
        leftPid();
        forward();
    }
    else if(wallAvailable[0] == 0 && wallAvailable[2] == 0)
    {
        forwardBase();
    }
}  
