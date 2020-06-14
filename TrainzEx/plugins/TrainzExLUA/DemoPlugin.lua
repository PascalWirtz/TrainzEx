--
--	AVAILABLE CALLBACKS
--

-- 	PostMessage(major, minor)
-- 	With PostMessage you can post messages back into Trainz

--	AddHandler
--	Please only call this function in OnInit.

--	RemoveHandler
--	Please only call this function in OnExit.



--
--	OnInit
--	Called once on startup
--
function OnInit()
	AddHandler("Interface", "")				-- Register myself for all Interface messages
end

--
--	OnExit
--	Called once when shutting down
--
function OnExit()
	RemoveHandler("Interface", "")			-- Unregister myself from all Interface messages
end

--
--	OnMessage
--	Called when within a message is posted that matches one of the handlers registered by AddHandler
--		major: Major string of the message
--		minor: Minor string of the message
--
function OnMessage(major, minor)
											-- No you will receive all Interface messages trough this function
end
