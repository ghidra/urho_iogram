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

        //UI* ui = GetSubsystem<UI>();
        //XMLFile* style = cache->GetResource<XMLFile>("UI/IogramDefaultStyle.xml");
        //ui->GetRoot()->SetDefaultStyle(style);
        //uiStyle = GetEditorUIXMLFile("UI/IogramDefaultStyle.xml");

        window = LoadEditorUI("UI/EditorIogramWindow.xml");
        //window.defaultStyle = uiStyle;
        ui.root.AddChild(window);
        window.opacity = uiMaxOpacity;

        window.height = 300;
        window.SetPosition(ui.root.width - 10 - window.width, attributeInspectorWindow.position.y + attributeInspectorWindow.height + 20);

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