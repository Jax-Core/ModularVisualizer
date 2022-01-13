mediaPlayers = {'AIMP', 'CAD', 'WMP', 'iTunes', 'Winamp', 'WebNowPlaying', 'Modern'}
havePlaying = false
activated = false

function Initialize()
    SKIN:Bang('[!Delay 1000][!CommandMeasure Func "checkMedia()"]')
end

function checkMedia()
    for i = 1, 7 do
        if SKIN:GetMeasure('state'..mediaPlayers[i]):GetValue() ~= 0 then
            havePlaying = true
            break
        else
            havePlaying = false
        end
    end
    if havePlaying == true and activated == false then
        SKIN:Bang('[!ActivateConfig "ModularVisualizer\\Main"]')
        activated = true
    else
        SKIN:Bang('[!DeactivateConfig "ModularVisualizer\\Main"]')
        activated = false
    end
end