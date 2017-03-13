class IogramEditor
{
	private bool dirty = true;
	private Window@ window;
    private UIElement@ toolbar;
    private Text@ currentToolDescText;

    private Slider@ brushSizeSlider;
    private Slider@ brushOpacitySlider;
    private Slider@ brushHeightSlider;

    void Create()
    {
        if (window !is null)
            return;

        window = LoadEditorUI("UI/EditorIogramWindow.xml");
        ui.root.AddChild(window);
        window.opacity = uiMaxOpacity;

        BorderImage@ currentToolDesc = window.GetChild("CurrentToolDesc", true);
        currentToolDesc.layoutBorder = IntRect(8, 8, 8, 8);

        currentToolDescText = window.GetChild("CurrentToolDescText", true);

        window.height = 300;
        window.SetPosition(ui.root.width - 40 - window.width, attributeInspectorWindow.position.y + attributeInspectorWindow.height + 40);

        Show();
    }

    // Hide the window
    void Hide()
    {
        window.visible = false;
    }

    bool Show()
    {
        window.visible = true;
        window.BringToFront();
        return true;
    }

    // Update the UI
    void UpdateDirty()
    {
        if (!dirty)
            return;

        dirty = false;
    }

}