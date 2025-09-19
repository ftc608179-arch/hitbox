--// Delta Anti-Hit Script (Air Lock Only)
--// LULU Protocol v7 Chronicle

local Players = game:GetService("Players")
local lp = Players.LocalPlayer
local playerGui = lp:WaitForChild("PlayerGui")

local proxy

-- GUI ボタン生成
local screenGui = Instance.new("ScreenGui")
screenGui.Name = "AirHitboxGUI"
screenGui.Parent = playerGui

local button = Instance.new("TextButton")
button.Size = UDim2.new(0, 200, 0, 50)
button.Position = UDim2.new(0.5, -100, 0.9, 0)
button.Text = "Air Hitbox ON"
button.Parent = screenGui

-- キャラ初期化
lp.CharacterAdded:Connect(function(char)
    char:WaitForChild("HumanoidRootPart")
    char:WaitForChild("Humanoid")

    -- 本体の当たり判定を無効化
    for _, part in ipairs(char:GetDescendants()) do
        if part:IsA("BasePart") then
            part.CanCollide = false
        end
    end

    -- 代理ヒットボックス生成
    proxy = Instance.new("Part")
    proxy.Name = "AirHitboxProxy"
    proxy.Size = Vector3.new(5, 7, 5)
    proxy.Anchored = true
    proxy.Transparency = 1
    proxy.CanCollide = true
    proxy.Parent = workspace
end)

-- ボタン押下で空中固定
button.MouseButton1Click:Connect(function()
    if proxy then
        proxy.CFrame = CFrame.new(0, 500, 0) -- 空中固定座標
        button.Text = "Air Hitbox Active"
    end
end)
