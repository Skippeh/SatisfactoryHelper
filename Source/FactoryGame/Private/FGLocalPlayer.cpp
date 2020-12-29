// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGLocalPlayer.h"

UFGEM_LoggedOutFromOnlineService::UFGEM_LoggedOutFromOnlineService() : Super() {
	this->mErrorMessage = NSLOCTEXT("ErrorMessages", "LoggedOutFromOnlineService", "You got sent to main menu as you got logged out from the online service. Your game was autosaved. You need to relaunch the game from the launcher to login again (sorry for the temporary solution)");
}
UFGEM_LostConnectionWithOnlineService::UFGEM_LostConnectionWithOnlineService() : Super() {
	this->mErrorMessage = NSLOCTEXT("ErrorMessages", "LostConnectionWithOnlineService", "You got sent to main menu as you lost connection with the online service. Your game was autosaved. You need to relaunch the game from the launcher to login again (sorry for the temporary solution)");
}
UFGEM_FailedToLoginToOnlineService::UFGEM_FailedToLoginToOnlineService() : Super() {
	this->mErrorMessage = NSLOCTEXT("ErrorMessages", "FailedToLoginToOnlineService", "Failed to login to the online service. You need to relaunch the game from the launcher to login again (sorry for the temporary solution)");
}
FFGOnlineFriend::FFGOnlineFriend(){ }
FFGOnlineFriend::FFGOnlineFriend(TSharedRef<FOnlineFriend> onlineFriend){ }
void FSessionInformation::Init(const FString& InMapName, const FString& InOptions, const FString& InSessionName, ESessionVisibility InVisibility){ }
void FSessionInformation::SendAnalytics(UWorld* world){ }
void FSessionInformation::MarkAsOffline(){ }
void FSessionInformation::SetState(ECreateSessionState newState, FOnCreateSessionStateChanged& createSessionChanged){ }
UFGLocalPlayer::UFGLocalPlayer() : Super() {
	
}
void UFGLocalPlayer::PlayerAdded( UGameViewportClient* inViewportClient, int32 inControllerID){ }
void UFGLocalPlayer::PlayerRemoved(){ }
void UFGLocalPlayer::SubscribeToOptionUpdates(){ }
void UFGLocalPlayer::OnMaintainYAxisFOVUpdated(){ }
TEnumAsByte<ELoginState> UFGLocalPlayer::GetLoginState() const{ return TEnumAsByte<ELoginState>(); }
FString UFGLocalPlayer::GetUsername() const{ return FString(); }
FString UFGLocalPlayer::GetUsernameEpic() const{ return FString(); }
FString UFGLocalPlayer::GetUsernameSteam() const{ return FString(); }
bool UFGLocalPlayer::GetFriendList(TArray<FFGOnlineFriend>& out_friends){ return bool(); }
void UFGLocalPlayer::AutoLogin(){ }
void UFGLocalPlayer::SetupServerAndTravelToMap(const FString& mapName, const FString& options, const FString& sessionName, ESessionVisibility visibility){ }
void UFGLocalPlayer::CopyPresenceDataToLocalPresenceAndPushToServer(const TSharedRef<FOnlineUserPresence>& presence){ }
void UFGLocalPlayer::UpdatePresence(){ }
void UFGLocalPlayer::CheckForStartupArguments(){ }
void UFGLocalPlayer::TestSteamCommandLineArgs(FString &sessionId){ }
void UFGLocalPlayer::SetNextUpdatePresenceTime(float timeTillNextUpdate){ }
void UFGLocalPlayer::OnInviteReceived(const FPendingInvite& invite){ }
void UFGLocalPlayer::RefreshRecentRegisteredSocialAccountID(){ }
bool UFGLocalPlayer::HasReceivedProductUserId() const{ return bool(); }
TSharedPtr<const FUniqueNetId> UFGLocalPlayer::GetPlayerId() const{ return TSharedPtr<const FUniqueNetId>(); }
TSharedPtr<const FUniqueNetId> UFGLocalPlayer::GetPlayerIdSteam() const{ return TSharedPtr<const FUniqueNetId>(); }
void UFGLocalPlayer::ConnectAccount(const FName currentPlatform){ }
void UFGLocalPlayer::LogOutEpicAndCreateNewAccountConnection(const FName currentPlatform){ }
void UFGLocalPlayer::CreateNewAccountConnection(const FName currentPlatform){ }
void UFGLocalPlayer::BroadcastAccountConnectionStepResult(const FName currentPlatform, EEosAccountConnectionResult result){ }
void UFGLocalPlayer::LoginAndConnectAccount(const FName currentPlatform){ }
void UFGLocalPlayer::ContinueWithoutConnectingAccount(const FName currentPlatform){ }
void UFGLocalPlayer::SwitchController( APlayerController* PC){ }
void UFGLocalPlayer::LoginAndConnectOtherEpicAccount(){ }
void UFGLocalPlayer::ContinueWithAndHookUpSteamToEOSAfterEpicLogout(){ }
void UFGLocalPlayer::LogoutEpicAccountAndContinue(){ }
void UFGLocalPlayer::LoginEpicAccountPortal(){ }
void UFGLocalPlayer::LogoutEpicAccountPortal(){ }
void UFGLocalPlayer::OnLoginStatusChanged(int32 localUserNum, ELoginStatus::Type previous, ELoginStatus::Type current, const FUniqueNetId& userId){ }
void UFGLocalPlayer::OnLoginStatusChangedSteam(int32 localUserNum, ELoginStatus::Type previous, ELoginStatus::Type current, const FUniqueNetId& userId){ }
void UFGLocalPlayer::SteamTaskRetryWaiter(){ }
void UFGLocalPlayer::StartSteamEOSConnect(){ }
void UFGLocalPlayer::OnLoginComplete(int32 localUserNum, bool wasSuccessful, const FUniqueNetId& userId, const FString& error){ }
void UFGLocalPlayer::OnLoginCompleteSteam(int32 localUserNum, bool wasSuccessful, const FUniqueNetId& userId, const FString& error){ }
void UFGLocalPlayer::OnAutoLoginComplete(int32 localUserNum, bool wasSuccessful, const FUniqueNetId& userId, const FString& error){ }
void UFGLocalPlayer::OnAutoLoginCompleteSteam(int32 localUserNum, bool wasSuccessful, const FUniqueNetId& userId, const FString& error){ }
void UFGLocalPlayer::OnConnectionStatusChanged(const FString& serviceName, EOnlineServerConnectionStatus::Type lastConnectionState, EOnlineServerConnectionStatus::Type connectionState){ }
void UFGLocalPlayer::OnConnectionStatusChangedSteam(const FString& serviceName, EOnlineServerConnectionStatus::Type lastConnectionState, EOnlineServerConnectionStatus::Type connectionState){ }
void UFGLocalPlayer::OnReadFriendsListComplete(int32 localUserNum, bool wasSuccessful, const FString& listName, const FString& errorStr){ }
void UFGLocalPlayer::OnReadFriendsListCompleteSteam(int32 localUserNum, bool wasSuccessful, const FString& listName, const FString& errorStr){ }
void UFGLocalPlayer::OnFriendsChange(){ }
void UFGLocalPlayer::OnFriendsChangeSteam(){ }
void UFGLocalPlayer::OnQueryUserInfoForFriendListComplete(int32 localUSerNum, bool wasSuccessful, const TArray< TSharedRef<const FUniqueNetId> >& userIds, const FString& errorString){ }
void UFGLocalPlayer::OnPresenceReceived(const  FUniqueNetId& userId, const TSharedRef<FOnlineUserPresence>& presence){ }
void UFGLocalPlayer::OnPresenceReceivedSteam(const  FUniqueNetId& userId, const TSharedRef<FOnlineUserPresence>& presence){ }
void UFGLocalPlayer::OnPreviousSessionCleanedup_SetupServer(FName sessionName, bool wasSuccessful){ }
void UFGLocalPlayer::OnSessionCreated_SetupServer(FName sessionName, bool wasSuccessful){ }
void UFGLocalPlayer::OnPresenceUpdated_SetupServer(const  FUniqueNetId& userId, const TSharedRef<FOnlineUserPresence>& presence){ }
void UFGLocalPlayer::OnLoginFailed_OpenMap(bool confirmClicked){ }
void UFGLocalPlayer::OnPresenceFailedToUpdate_OpenMap(bool confirmClicked){ }
void UFGLocalPlayer::UpdateLoginState(){ }
void UFGLocalPlayer::CreateOfflineSession_SetupServer(bool startOffline){ }
bool UFGLocalPlayer::CanAutoLoginEpic() const{ return bool(); }
bool UFGLocalPlayer::CanAutoLoginSteam() const{ return bool(); }
FString UFGLocalPlayer::GetPresenceString() const{ return FString(); }
void UFGLocalPlayer::GetPresenceState(FPlayerPresenceState& outState) const{ }
ELoginState UFGLocalPlayer::FromLoginStatus(ELoginStatus::Type from) const{ return ELoginState(); }
void UFGLocalPlayer::OpenMap_WaitForPresence(){ }
void UFGLocalPlayer::OpenMap_WaitForProductUserId(){ }
void UFGLocalPlayer::OpenMap(){ }
ECreateSessionState UFGLocalPlayer::GetCurrentCreateSessionState() const{ return ECreateSessionState(); }
void UFGLocalPlayer::OnLoggedIn(){ }
void UFGLocalPlayer::SetLoginStateEpic(ELoginState newLoginState){ }
void UFGLocalPlayer::SetLoginStateSteam(ELoginState newLoginState){ }
void UFGLocalPlayer::GetFriendsWithNoData(TArray<TSharedRef<const FUniqueNetId>>& out_usersWithNoData){ }
bool UFGLocalPlayer::PresenceHasSessionId() const{ return bool(); }
void UFGLocalPlayer::PushErrorAndAutosave(TSubclassOf<class UFGErrorMessage> errorMessage){ }
void UFGLocalPlayer::OnComandlineInviteSearchComplete(FBlueprintSessionResult result){ }
